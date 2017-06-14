#include <iostream>
#include <fstream>
#include <string>


int buddyinfo();
int cpuinfo();
int consoles();


int main() {
    buddyinfo();
    std::cout<<"----------------------------------------------"<<std::endl;
    cpuinfo();
    std::cout<<"----------------------------------------------"<<std::endl;
    consoles();



//    std::ifstream f("/proc/cpuinfo");
//    std::string s;
//    int i = 0;
//    while(getline(f, s))
//    {  // if (i == 0 || i == 4 || i == 7 || i == 8 || i == 27 || i == 31|| i == 38 || i == 39 || i == 54) {
//            std::cout << s << std::endl;
//      //  }
//       // i+=1;
//    }


//    std::ifstream fi("ls /proc");//в терміналі і тоді аналіз
//    std::string si;
//    while(getline(fi, si))
//    {
//            std::cout << si << std::endl;
//        }

    return 0;
}

int buddyinfo() {
    /*
     * External fragmentation is a problem under some workloads, and buddyinfo is a
    useful tool for helping diagnose these problems.  Buddyinfo will give you a
    clue as to how big an area you can safely allocate, or why a previous
    allocation failed.

    Each column represents the number of pages of a certain order which are
    available.  In this case, there are 3 chunks of 2^0*PAGE_SIZE available in
    ZONE_DMA, 0 chunks of 2^1*PAGE_SIZE in ZONE_DMA, 221 chunks of 2^4*PAGE_SIZE
    available in ZONE_NORMAL, etc...

    More information relevant to external fragmentation can be found in
    pagetypeinfo.
     */
    std::cout<<"buddyinfo:"<<std::endl;
    std::ifstream f("/proc/buddyinfo");//cat
    std::string s;
    while (getline(f, s)) {
        std::cout << s << std::endl;
    }
    return 0;
}

int cpuinfo() {
    std::cout<<"cpuinfo:"<<std::endl;
    std::ifstream f("/proc/cpuinfo");
    std::string s;
    int i = 0;
    while (getline(f, s)) {
        if (i == 0 || i == 4 || i == 7 || i == 8 || i == 27 || i == 54) {
        std::cout << s << std::endl;
      }
     i+=1;
    }
    return 0;
}

int consoles(){
    /*
     * Shows registered system console lines.
    To see which character device lines are currently used for the system console
    /dev/console, you may simply look into the file /proc/consoles:
     The columns are:

  device               name of the device
  operations           R = can do read operations
                       W = can do write operations
                       U = can do unblank
  flags                E = it is enabled
                       C = it is preferred console
                       B = it is primary boot console
                       p = it is used for printk buffer
                       b = it is not a TTY but a Braille device
                       a = it is safe to use when cpu is offline
  major:minor          major and minor number of the device separated by a colon
    */
    std::cout<<"consoles: "<<std::endl;
    std::ifstream f("/proc/consoles");
    std::string s;
    while (getline(f, s)) {
        std::cout << s << std::endl;
    }
    return 0;

}