#include <Windows.h>
#include <stdio.h>

int is_debugger_present() {
    int debugger_present = 0;
    __asm {
        mov eax, fs: [30h]
        mov eax, [eax + 2]
        and eax, 1
        mov debugger_present, eax
    }
    return debugger_present;
}

int main(void) {
    if (is_debugger_present()) {
        printf("Debugger detected\n");
        exit(1);
    }

    else {
        printf("Debugger not detected\n");
    }

    printf("program continuation\n");
    return 0;
}
