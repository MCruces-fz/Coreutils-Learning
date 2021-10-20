#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define FLAG_X 1
#define FLAG_Y 2
#define FLAG_Z 4
#define FLAG_M 8
#define FLAG_N 16
#define FLAG_O 32
#define FLAG_P 64
#define FLAG_Q 128
#define FLAG_R 256

char* program_name;

static struct option const long_options[] = {
  {"flag-x", no_argument, NULL, 'x'},
  {"flag-y", no_argument, NULL, 'y'},
  {"flag-z", no_argument, NULL, 'z'},
  {"flag-m", no_argument, NULL, 'm'},
  {"flag-n", no_argument, NULL, 'n'},
  {"flag-o", no_argument, NULL, 'o'},
  {"flag-p", no_argument, NULL, 'p'},
  {"flag-q", no_argument, NULL, 'q'},
  {"flag-r", no_argument, NULL, 'r'},
  {NULL, 0, NULL, 0}
};

static inline void emit_try_help (void) {
  fprintf (stderr, "Try '%s --help' for more information.\n", program_name);
}

void usage (int status) {
    if (status != EXIT_SUCCESS) {
        // printf("status != EXIT_SUCCESS\n");
        emit_try_help ();
    } else {
        printf ("Usage: %s [OPTION]...\n", program_name);
        
        fputs ("\
Print certain system information.  With no OPTION, same as -s.\n\
\n\
  -a, --all                print all information, in the following order,\n\
                             except omit -p and -i if unknown:\n\
  -s, --kernel-name        print the kernel name\n\
  -n, --nodename           print the network node hostname\n\
  -r, --kernel-release     print the kernel release\n\
", stdout);
        fputs ("\
  -v, --kernel-version     print the kernel version\n\
  -m, --machine            print the machine hardware name\n\
  -p, --processor          print the processor type (non-portable)\n\
  -i, --hardware-platform  print the hardware platform (non-portable)\n\
  -o, --operating-system   print the operating system\n\
", stdout);

        // fputs (HELP_OPTION_DESCRIPTION, stdout);
        // fputs (VERSION_OPTION_DESCRIPTION, stdout);
        // emit_ancillary_info (PROGRAM_NAME);
    }
    exit (status);
}


static int decode_switches(int argc, char** argv) {
    int c;
    unsigned int flags = 0;

    while ((c = getopt_long(argc, argv, "xyzmnopqr", 
                            long_options, NULL)) != -1) {

        switch (c) {
            case 'x':
                flags |= FLAG_X;
                break;
            case 'y':
                flags |= FLAG_Y;
                break;
            case 'z':
                flags |= FLAG_Z;
                break;
            case 'm':
                flags |= FLAG_M;
                break;
            case 'n':
                flags |= FLAG_N;
                break;
            case 'o':
                flags |= FLAG_O;
                break;
            case 'p':
                flags |= FLAG_P;
                break;
            case 'q':
                flags |= FLAG_Q;
                break;
            case 'r':
                flags |= FLAG_R;
                break;
            default:
                usage(EXIT_FAILURE);
        }
    }

    return flags;
}

int main(int argc, char** argv) {
    unsigned int flags = 0;
    program_name = argv[0];

    flags = decode_switches(argc, argv);

    if (flags 
         & ( FLAG_X | FLAG_Y | FLAG_Z | FLAG_M | FLAG_N 
             | FLAG_O |FLAG_P | FLAG_Q | FLAG_R )){

        if (flags & FLAG_X) {
            printf("Heello Mr/Mrs!\n");
        }
        if (flags & FLAG_Y) {
            printf("Byeee Mr/Mrs!\n");
        }
    }
}

