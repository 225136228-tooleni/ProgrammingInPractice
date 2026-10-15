MFMS Week 9 - Multi-File Programming

Modules:
main.c      - menu
employees.c - employee functions
budget.c    - budget functions
utilities.c - input helpers
reports.c   - reports

Build:
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc main.o employees.o budget.o utilities.o reports.o -o mfms

Run:
./mfms
