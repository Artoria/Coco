.int 0x44434241
.int 0x44434241
.int 0x44434241
.int 0x44434241
push %ebp
               mov %esp, %ebp
            push $4
              push $53430960
              push $53430960
              push $3568560
              mov $1799394564, %eax
              call *%eax
              add $16, %esp
              leave
         ret $16
        .int 0x64636261
.int 0x64636261
.int 0x64636261
.int 0x64636261

.globl _start
_start:
