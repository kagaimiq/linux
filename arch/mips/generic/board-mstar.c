#include <linux/of.h>

#include <asm/bootinfo.h>
#include <asm/machine.h>

static const struct of_device_id mstar_of_match[] __initconst = {
	{ .compatible = "mstar,kronus", },
	{ .compatible = "mstar,titania4", },
};

static __init const void *mstar_fixup_fdt(const void *fdt, const void *data)
{
	system_type = "MStar MIPS SoC";
	return fdt;
}

MIPS_MACHINE(mstar) = {
	.matches		= mstar_of_match,
	.fixup_fdt		= mstar_fixup_fdt,
};
