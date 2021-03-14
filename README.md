# Corewar

## Instruction

- Add asm binary path to ASM_PATH inside Makefile
- Add corewar binary path to VM_PATH inside Makefile
- Run Comprehensive test using `make tests`

## Test Descriptions
### General Tests
| Test syntax | Description |
| ---------- | ----------- |
| `make tests` | Run comprehensive test on asm and vm |
| `make tests_leaks` | Run leak test on asm and vm |
| `make tests_asm_leak` | Run leak test on asm |
| `make tests_vm_leak` | Run leak test on vm |
| `make tests_asm` | Run comprehensive test on asm |
| `make tests_vm` | Run comprehensive test on vm |
### Assembler Tests
| Test syntax|Description|
|---------- |---------- |
| `make tests_asm_error` | Run error test case on asm, by comparing return value from main. Expected value is -1 for exit with error |
| `make tests_asm_bin` | Run valid test case on asm, by comparing binaries (.cor) |
### Corewar Tests
|Test syntax|Description|
|---------- |---------- |
| `make tests_vm_error` | Run error test case on vm, by comparing return value from main. Expected value is -1 for exit with error |
| `make tests_vm_op` | Run test case focused on simple operation by comparing -v 30|
| `make tests_vm_ocp` | Run test case focused on different ocp by comparing -v 30|
| `make tests_vm_dump` | Run test case focused on simple operation by comparing memory dumps using option -dump |
| `make tests_vm_op_champs` | Run test case focused on operation used by champs by comparing -v 30 |
| `make tests_vm_dump_champs` | Run test case focused on operation used by champs by comparing memory dumps using option -dump|
| `make tests_vm_op_overflow` | Run test case focused on overflow by comparing -v 30 |
| `make tests_vm_dump_overflow` | Run test case focused on overflow by comparing memory dumps using option -dump|
| `make tests_vm_battle` | Run test case focus battle between two champs by comparing -v 30|
