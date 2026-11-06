#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>

static int __init test_init(void) {
    struct kprobe kp = {
        .symbol_name = "kallsyms_lookup_name"
    };
    register_kprobe(&kp);
    unregister_kprobe(&kp);
    
    pr_info("CAK_TEST: Module loaded. kallsyms at %px\n", kp.addr);
    return 0;
}

static void __exit test_exit(void) {
    pr_info("CAK_TEST: Module unloaded.\n");
}

module_init(test_init);
module_exit(test_exit);
MODULE_LICENSE("GPL");
