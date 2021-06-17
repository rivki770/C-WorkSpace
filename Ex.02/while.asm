    int i = 0;
00241888  mov         dword ptr [i],0  

    while (i < 5)
0024188F  cmp         dword ptr [i],5  
00241893  jge         main+64h (02418C4h)  
    {
        i++;
00241895  mov         eax,dword ptr [i]  
00241898  add         eax,1  
0024189B  mov         dword ptr [i],eax  
        if ((i % 2) == 0)
0024189E  mov         eax,dword ptr [i]  
002418A1  and         eax,80000001h  
002418A6  jns         main+4Dh (02418ADh)  
002418A8  dec         eax  
002418A9  or          eax,0FFFFFFFEh  
002418AC  inc         eax  
002418AD  test        eax,eax  
002418AF  jne         main+62h (02418C2h)  
        {
            printf("%d\n", i);
002418B1  mov         eax,dword ptr [i]  
002418B4  push        eax  
002418B5  push        offset string "%d\n" (0247B30h)  
002418BA  call        _printf (02410CDh)  
002418BF  add         esp,8  
        }
    }
002418C2  jmp         main+2Fh (024188Fh)  

    return 0;
002418C4  xor         eax,eax  
}