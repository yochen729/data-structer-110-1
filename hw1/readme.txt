1.	第一題：
    我是使用struct來存資料，找到符合的就輸出。
2.	第二題：
    首先處理input 的Ciphertext資料，然後KOT13解碼，取前五個字元產生key，再取得input的article，以及用struct儲存input 的answer_dic，然後輸出KOT13解碼後的字串和Key。接下來用Failure     Array 去計算lps總和，再輸出總和，再用KMP去找key在article中的位址，儲存起來並加上lps總和再輸出數值，最後在answer_dic找到數值代表的意思並輸出結果。
    
    KMP的部分我是參考書上的程式碼，程式碼是大概懂了，但有些地方還不太了解，其中的Failure Array的部分已經懂了。
