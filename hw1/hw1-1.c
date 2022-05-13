#include <stdio.h>
#include <string.h>

struct info
{
    //**資料的結構**//
    char Id[11];
    char Name[26];
    char Vaccine_brand[31];
    int Age;
    char City[21];
};

int main()
{
    int num_of_data;
    struct info vaccineInfo[20];
    scanf("%d",&num_of_data);
    //** 總共有幾人**//

    int count;
    for( count = 0 ; count < num_of_data ; count ++ )
    {
        //**資料輸入**//
        scanf("%s",&vaccineInfo[count].Id);
        scanf("%s",&vaccineInfo[count].Name);
        scanf("%s",&vaccineInfo[count].Vaccine_brand);
        scanf("%d",&vaccineInfo[count].Age);
        scanf("%s",&vaccineInfo[count].City);
    }

    char Find[30];
    scanf("%s",Find);
    //**想找的資料**//

    for( count = 0 ; count < num_of_data ; count ++ )
    {
        //**找到的話就輸出**//
        if(strcmp(Find,vaccineInfo[count].Vaccine_brand) == 0)
        {
            printf("%s ",vaccineInfo[count].Id);
            printf("%s ",vaccineInfo[count].Name);
            printf("%s ",vaccineInfo[count].Vaccine_brand);
            printf("%d ",vaccineInfo[count].Age);
            printf("%s\n",vaccineInfo[count].City);
        }
    }

    return 0;
}