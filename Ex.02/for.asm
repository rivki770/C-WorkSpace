for (int i = 1; i < 5; i++)
00201888  mov         dword ptr [ebp-8],1  
0020188F  jmp         main+3Ah (020189Ah)  
00201891  mov         eax,dword ptr [ebp-8]  
00201894  add         eax,1  
00201897  mov         dword ptr [ebp-8],eax  
0020189A  cmp         dword ptr [ebp-8],5  
0020189E  jge         main+66h (02018C6h)  
    {
        if ((i % 2) == 0)
002018A0  mov         eax,dword ptr [ebp-8]  
002018A3  and         eax,80000001h  
002018A8  jns         main+4Fh (02018AFh)  
002018AA  dec         eax  
002018AB  or          eax,0FFFFFFFEh  
002018AE  inc         eax  
002018AF  test        eax,eax  
002018B1  jne         main+64h (02018C4h)  
        {
            printf("%d\n", i);
002018B3  mov         eax,dword ptr [ebp-8]  
002018B6  push        eax  
002018B7  push        offset string "%d\n" (0207B30h)  
002018BC  call        _printf (02010CDh)  
002018C1  add         esp,8  
        }
    }
002018C4  jmp         main+31h (0201891h)  
    return 0;
002018C6  xor         eax,eax  
}