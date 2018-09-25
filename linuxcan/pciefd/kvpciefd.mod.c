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
	{ 0xea3f725d, __VMLINUX_SYMBOL_STR(_raw_write_lock_irqsave) },
	{ 0x147872db, __VMLINUX_SYMBOL_STR(pci_disable_device) },
	{ 0xfbd676c6, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x6d5cdac0, __VMLINUX_SYMBOL_STR(pci_release_regions) },
	{ 0x9580deb, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xd20f3020, __VMLINUX_SYMBOL_STR(_raw_write_unlock_irqrestore) },
	{ 0xbfc177bc, __VMLINUX_SYMBOL_STR(iowrite32_rep) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x351186f8, __VMLINUX_SYMBOL_STR(queue_empty) },
	{ 0x64ab0e98, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x3f5edb99, __VMLINUX_SYMBOL_STR(pci_set_master) },
	{ 0x706d051c, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xe395e126, __VMLINUX_SYMBOL_STR(queue_front) },
	{ 0x7425793, __VMLINUX_SYMBOL_STR(vCanDispatchEvent) },
	{ 0x13ff1b98, __VMLINUX_SYMBOL_STR(pci_iounmap) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x65c544a3, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0x6250a0e9, __VMLINUX_SYMBOL_STR(set_capability_value) },
	{ 0x711f3702, __VMLINUX_SYMBOL_STR(queue_wakeup_on_space) },
	{ 0xd9154dd1, __VMLINUX_SYMBOL_STR(queue_pop) },
	{ 0x235ea4c1, __VMLINUX_SYMBOL_STR(calculateCRC32) },
	{ 0x1bb31047, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x2072ee9b, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0xbe067e1f, __VMLINUX_SYMBOL_STR(pci_clear_master) },
	{ 0xe2f3d61a, __VMLINUX_SYMBOL_STR(vCanInitData) },
	{ 0xcc82add3, __VMLINUX_SYMBOL_STR(_raw_read_lock_irqsave) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0xe5815f8a, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x3d1391e2, __VMLINUX_SYMBOL_STR(_raw_read_unlock_irqrestore) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x55b726bb, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0xbfe1152b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xf7b1b3bf, __VMLINUX_SYMBOL_STR(set_capability_mask) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xbd4bcfa1, __VMLINUX_SYMBOL_STR(queue_irq_lock) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xe9744cf1, __VMLINUX_SYMBOL_STR(pci_request_regions) },
	{ 0x6024c80d, __VMLINUX_SYMBOL_STR(dma_supported) },
	{ 0x18d73a36, __VMLINUX_SYMBOL_STR(vCanInit) },
	{ 0xa15ac66f, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0x72758a, __VMLINUX_SYMBOL_STR(queue_reinit) },
	{ 0x9f6608f5, __VMLINUX_SYMBOL_STR(queue_release) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb2d5a552, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x3e67fc31, __VMLINUX_SYMBOL_STR(pci_iomap) },
	{ 0x436c2179, __VMLINUX_SYMBOL_STR(iowrite32) },
	{ 0x82fa1117, __VMLINUX_SYMBOL_STR(pci_enable_device) },
	{ 0x200d5dec, __VMLINUX_SYMBOL_STR(dma_ops) },
	{ 0xe484e35f, __VMLINUX_SYMBOL_STR(ioread32) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kvcommon";


MODULE_INFO(srcversion, "56DEAAD0F48A0EA65FB522C");
