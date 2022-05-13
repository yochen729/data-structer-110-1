#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Maxtext 128
#define Maxwordtext 512

void get_secret_Ciphertext(char text[]);
void get_key(char Ciphertext[],char Key[]);
void get_article(char text[]);
int find_key_lps_sum(char Key[]);
void do_KMP(char all[],char find[],int position[]);
void failure(char p[],int len,int f[] );

typedef struct info
{
    char alpha;
    char phrase[32];
    /**
     * @結構
     */
}answer;

int main()
{
    char Ciphertext[Maxtext];
    char Key[6];
    get_secret_Ciphertext(Ciphertext);
    /**
     * @取得Ciphertext並使用KOT13解碼
     */
    get_key(Ciphertext,Key);
    /**
     * @取得key
     */
    char article[Maxwordtext];
    get_article(article);
    /**
     * @取得article
     */
    answer answer_dic[52];
    int i,j;
    for(i=0;i<52;i++)
    {
        scanf("%c,",&answer_dic[i].alpha);
        fgets(answer_dic[i].phrase,32,stdin);
        for(j=0;answer_dic[i].phrase[j]!='\n';j++)
        {}
        answer_dic[i].phrase[j] = '\0';
    }
    /**
     * @取得answer_dic
     */
    printf("%s\n",Ciphertext);
    printf("%s\n",Key);
    /**
     * @輸出KOT13解碼後的字串和Key
     */
    int key_lps_sum = find_key_lps_sum(Key);
    printf("%d\n",key_lps_sum);
    /**
     * @輸出Key的lps_array的總和
     */
    int position[128];
    for( i = 0 ; i < 128 ; i++ )
    {
        position[i] = -1;
        /**
        * @初始化
        */
    }
    do_KMP(article,Key,position);
    for( i = 0 ; position[i] != -1 ; i++ )
    {
        position[i]+=key_lps_sum;
        printf("%d\n",position[i]);
        /**
        * @使用KMP並找出數值
        */
    }
    for( i = 0 ; position[i] != -1 ; i++ )
    {
        if(position[i]>=65&&position[i]<=90)
        {
            printf("%s ",answer_dic[position[i] - 'A'].phrase);
        }
        else
        {
            printf("%s ",answer_dic[position[i] - 'a' + 26].phrase);
        }
        /**
        * @找出數值代表的片語
        */
    }
    printf("\n");
    return 0;
}

void get_secret_Ciphertext(char text[])
{
    fgets(text,Maxtext,stdin);
    int i;
    for( i = 0 ; text[i] != '\n' ; i ++ )
    {
        /**
         * @使用KOT13解碼
         */
        if(isupper(text[i]))
        {
            if(text[i]>'m')
            {
                text[i]-=13;
            }
            else
            {
                text[i]+=13;
            }
        }
        else
        {
            if(text[i]>'m')
            {
                text[i]-=13;
            }
            else
            {
                text[i]+=13;
            }
        }
    }
    text[i] = '\0';
    /**
     * @字串結尾加'\0'
     */
}

void get_key(char Ciphertext[],char Key[])
{
    int i;
    for( i = 0 ; i < 5 ; i ++ )
    {
        Key[i] = Ciphertext[i];
    }
    Key[5]='\0';
    /**
    * @讓key等於前五個字母,並在結尾加上'\0'
    */
}

void get_article(char text[])
{
    fgets(text,Maxwordtext,stdin);
}

int find_key_lps_sum(char Key[])
{
    int len = strlen(Key);
    int lps_arr[5];
    failure(Key,len,lps_arr);
    int i,sum=0;
    for(i=0;i<5;i++)
    {
        sum+=lps_arr[i];
        /**
         * @lps的加總
         */
    }
    return sum;
}

void do_KMP(char all[],char find[],int position[])
{
    int count_of_position = 0;
    int all_len = strlen(all);
    int find_len = strlen(find);
    /**
     * @算長度
     */
    int fail[find_len];
    failure(find,find_len,fail);
    int i = 0;
    int j = 0;
    /**
     * @i是整個的位置 
     * @j是字串的位置
     */
    while (i < all_len) 
    {
        if (find[j] == all[i]) 
        {
            j++;
            i++;
            /**
             * @match到就繼續
             */
        }
        if (j == find_len) 
        {
            position[count_of_position] = i - j;
            count_of_position++;
            j = fail[j-1];
            /**
             * @當j=長度代表全部match了
             * @紀錄位置並尋找下一個
             */
        }
        else if (i < all_len && find[j] != all[i]) 
        {
            if (j != 0)
            {
                j = fail[j-1];
                /**
                 * @如果j不是0就往回找
                 */
            }
            else
            {
                i++;
                /**
                 * @如果j是0代表都沒有match
                 * @就往前一步
                 */
            }
        }
    }
}

void failure(char p[],int len,int f[] )
{
    int i = 1;
    int j = 0;
    f[0] = 0;
    while(i < len)
    {
        /**
         * @i會一個一個往後
         * @j會往後又往回
         */
        if(p[j] == p[i])
        {
            f[i] = j+1;
            i++;
            j++;
            /**
            * @match到就繼續
            */
        }
        else if(j > 0)
        {
            j = f[j-1];
            /**
             * @如果j>0,就往前找看看有沒有match
             */
        }
        else
        {
            f[i] = 0;
            i++;
            /**
             * @直到j=0,代表沒有match,所以f[i]=0
             */
        }
    }
}