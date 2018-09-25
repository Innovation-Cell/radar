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
	{ 0xa615bdc5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xbefe600c, __VMLINUX_SYMBOL_STR(vCanCleanup) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xfbd676c6, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xa7e85edf, __VMLINUX_SYMBOL_STR(vCanTime) },
	{ 0x351186f8, __VMLINUX_SYMBOL_STR(queue_empty) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xe395e126, __VMLINUX_SYMBOL_STR(queue_front) },
	{ 0x7425793, __VMLINUX_SYMBOL_STR(vCanDispatchEvent) },
	{ 0x65c544a3, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x6250a0e9, __VMLINUX_SYMBOL_STR(set_capability_value) },
	{ 0x711f3702, __VMLINUX_SYMBOL_STR(queue_wakeup_on_space) },
	{ 0xd9154dd1, __VMLINUX_SYMBOL_STR(queue_pop) },
	{ 0xe2f3d61a, __VMLINUX_SYMBOL_STR(vCanInitData) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xbfe1152b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x18d73a36, __VMLINUX_SYMBOL_STR(vCanInit) },
	{ 0x9c049516, __VMLINUX_SYMBOL_STR(vCanFlushSendBuffer) },
	{ 0x9f6608f5, __VMLINUX_SYMBOL_STR(queue_release) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kvcommon";


MODULE_INFO(srcversion, "0E50A147F09682134A923F6");
