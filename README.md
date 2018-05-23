# imageCal


## II. 數學運算式
假設我們想開發一套數學運算軟體，可以對數學運算式進行編譯，並根據運算式計算結果。 <br />
運算式的數字均為正整數、運算元為四則運算，即加、減、乘、除等運算， <br />
分別使用+、-、* / 為運算符號。此外，運算式可能包含括號。運算須依括號優先，且是先乘除、後加減的順序。 <br />
注意：本程式僅須完成簡易的編譯工作，因此你可以假設運算式不含任何空格。除法若 <br />
除不盡，須計算小數點，精確度至小數點下 4 位即算正確。 <br />
輸入說明: <br />
輸入包含 n 個運算式，接著分成 n 列，每一列包含一個數學運算式，長度不超過 128 個字元。 <br />
輸出說明: <br />
若數學運算式正確，則輸出計算結果；否則輸出錯誤訊息。 <br />
輸入範例：<br />
7<br />
2+3-4<br />
10–3*2<br />
(3+2)*5<br />
7/4*3<br />
((3*2)+(2*4))<br />
((2+2)*3<br />
((1+2)+3)+4)<br />

輸出範例：<br />
1<br />
4<br />
25<br />
5.25<br />
14<br />
Error<br />
Erro<br />
