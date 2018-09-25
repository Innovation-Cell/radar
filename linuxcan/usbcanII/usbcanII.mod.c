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
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xa615bdc5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x50afbdd3, __VMLINUX_SYMBOL_STR(queue_init) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xbefe600c, __VMLINUX_SYMBOL_STR(vCanCleanup) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0xb6d109a1, __VMLINUX_SYMBOL_STR(queue_length) },
	{ 0xdddb28a2, __VMLINUX_SYMBOL_STR(seq_puts) },
	{ 0xfbd676c6, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x277e49f2, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x9580deb, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xca2e829b, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xffd5a395, __VMLINUX_SYMBOL_STR(default_wake_function) },
	{ 0x351186f8, __VMLINUX_SYMBOL_STR(queue_empty) },
	{ 0x26dd06ba, __VMLINUX_SYMBOL_STR(queue_push) },
	{ 0x64ab0e98, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x706d051c, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xe395e126, __VMLINUX_SYMBOL_STR(queue_front) },
	{ 0x938efd61, __VMLINUX_SYMBOL_STR(queue_add_wait_for_space) },
	{ 0x7425793, __VMLINUX_SYMBOL_STR(vCanDispatchEvent) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x65c544a3, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x8e5ac881, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x6250a0e9, __VMLINUX_SYMBOL_STR(set_capability_value) },
	{ 0x711f3702, __VMLINUX_SYMBOL_STR(queue_wakeup_on_space) },
	{ 0xd9154dd1, __VMLINUX_SYMBOL_STR(queue_pop) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x1bb31047, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x99457f76, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x952664c5, __VMLINUX_SYMBOL_STR(do_exit) },
	{ 0x42160169, __VMLINUX_SYMBOL_STR(flush_workqueue) },
	{ 0x1d4a0e66, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0xe2f3d61a, __VMLINUX_SYMBOL_STR(vCanInitData) },
	{ 0xc2690330, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xfb77ec2d, __VMLINUX_SYMBOL_STR(usb_bulk_msg) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x5d802f6e, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xbfe1152b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x18d73a36, __VMLINUX_SYMBOL_STR(vCanInit) },
	{ 0x9c049516, __VMLINUX_SYMBOL_STR(vCanFlushSendBuffer) },
	{ 0xc4ded348, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x3cbc4f98, __VMLINUX_SYMBOL_STR(queue_remove_wait_for_space) },
	{ 0x247488b4, __VMLINUX_SYMBOL_STR(queue_back) },
	{ 0x72758a, __VMLINUX_SYMBOL_STR(queue_reinit) },
	{ 0x9f6608f5, __VMLINUX_SYMBOL_STR(queue_release) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb2d5a552, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x865b7928, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x7f02188f, __VMLINUX_SYMBOL_STR(__msecs_to_jiffies) },
	{ 0x59909e73, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0xd87ac9e5, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xbfc1a3bb, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kvcommon";

MODULE_ALIAS("usb:v0BFDp0004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0005d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BFDp0003d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "21C27C120DB08596E9766CD");
