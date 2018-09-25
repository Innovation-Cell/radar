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
	{ 0xbefe600c, __VMLINUX_SYMBOL_STR(vCanCleanup) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x147872db, __VMLINUX_SYMBOL_STR(pci_disable_device) },
	{ 0xfbd676c6, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xeae3dfd6, __VMLINUX_SYMBOL_STR(__const_udelay) },
	{ 0x6d5cdac0, __VMLINUX_SYMBOL_STR(pci_release_regions) },
	{ 0xa7e85edf, __VMLINUX_SYMBOL_STR(vCanTime) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xe395e126, __VMLINUX_SYMBOL_STR(queue_front) },
	{ 0xf10de535, __VMLINUX_SYMBOL_STR(ioread8) },
	{ 0x7425793, __VMLINUX_SYMBOL_STR(vCanDispatchEvent) },
	{ 0x13ff1b98, __VMLINUX_SYMBOL_STR(pci_iounmap) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x65c544a3, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x6250a0e9, __VMLINUX_SYMBOL_STR(set_capability_value) },
	{ 0x711f3702, __VMLINUX_SYMBOL_STR(queue_wakeup_on_space) },
	{ 0xd9154dd1, __VMLINUX_SYMBOL_STR(queue_pop) },
	{ 0x235ea4c1, __VMLINUX_SYMBOL_STR(calculateCRC32) },
	{ 0x2072ee9b, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0xe2f3d61a, __VMLINUX_SYMBOL_STR(vCanInitData) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xfd06f019, __VMLINUX_SYMBOL_STR(packed_EAN_to_BCD_with_csum) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x727c4f3, __VMLINUX_SYMBOL_STR(iowrite8) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x55b726bb, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0xbfe1152b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe9744cf1, __VMLINUX_SYMBOL_STR(pci_request_regions) },
	{ 0x18d73a36, __VMLINUX_SYMBOL_STR(vCanInit) },
	{ 0xa15ac66f, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0x9c049516, __VMLINUX_SYMBOL_STR(vCanFlushSendBuffer) },
	{ 0x9f6608f5, __VMLINUX_SYMBOL_STR(queue_release) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x3e67fc31, __VMLINUX_SYMBOL_STR(pci_iomap) },
	{ 0x436c2179, __VMLINUX_SYMBOL_STR(iowrite32) },
	{ 0x82fa1117, __VMLINUX_SYMBOL_STR(pci_enable_device) },
	{ 0xe484e35f, __VMLINUX_SYMBOL_STR(ioread32) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kvcommon";


MODULE_INFO(srcversion, "5CEC22D58F2AB3F48A32E67");
