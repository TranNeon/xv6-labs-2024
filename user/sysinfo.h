// In kernel/sysinfo.h
struct sysinfo {
    uint64 freemem;     // Free memory in bytes
    uint32 nproc;       // Number of active processes
    uint32 nopenfiles;  // Number of open files
};