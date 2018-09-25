#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x3d6976bf, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x27c400b1, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xa615bdc5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x9041f1bb, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xc815137c, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x8526c35a, __VMLINUX_SYMBOL_STR(remove_wait_queue) },
	{ 0xd9d3bcd3, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x78bcdc29, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x6729d3df, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x167e7f9d, __VMLINUX_SYMBOL_STR(__get_user_1) },
	{ 0x7b4af9dc, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x50cc559d, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0x64ab0e98, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x65c544a3, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xc3aaf0a9, __VMLINUX_SYMBOL_STR(__put_user_1) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0xa9921b8, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xb2fd5ceb, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0xbba70a2d, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x6d334118, __VMLINUX_SYMBOL_STR(__get_user_8) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xbfe1152b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x263e6ebd, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0xc9fef317, __VMLINUX_SYMBOL_STR(add_wait_queue) },
	{ 0x1f385737, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb2d5a552, __VMLINUX_SYMBOL_STR(complete) },
	{ 0xe87daf6, __VMLINUX_SYMBOL_STR(seq_release) },
	{ 0x7f02188f, __VMLINUX_SYMBOL_STR(__msecs_to_jiffies) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4F4EA4A39EAF8443C0C1928");
