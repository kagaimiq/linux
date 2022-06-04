// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include "pinctrl-mtk-mt6580.h"
#include "pinctrl-paris.h"

#define PIN_FIELD_BASE(_s_pin, _e_pin, _i_base, _s_addr, _x_addrs, _s_bit, _x_bits)	\
	PIN_FIELD_CALC(_s_pin, _e_pin, _i_base, _s_addr, _x_addrs, _s_bit,	\
		       _x_bits, 32, 0)

static const struct mtk_pin_field_calc mt6580_pin_mode_range[] = {
	PIN_FIELD(0, 92, 0x54, 0x10, 0, 4),
};

static const struct mtk_pin_field_calc mt6580_pin_dir_range[] = {
	PIN_FIELD(0, 92, 0x0, 0xc, 0, 1),
};

static const struct mtk_pin_field_calc mt6580_pin_di_range[] = {
	PIN_FIELD(0, 92, 0x48, 0x4, 0, 1),
};

static const struct mtk_pin_field_calc mt6580_pin_do_range[] = {
	PIN_FIELD(0, 92, 0x24, 0xc, 0, 1),
};

static const struct mtk_pin_field_calc mt6580_pin_smt_range[] = {
	PIN_FIELD_BASE(0, 3, 1, 0x54, 0xc, 0, 1),
	PIN_FIELD_BASE(4, 8, 4, 0x54, 0xc, 6, 1),
	PIN_FIELD_BASE(9, 16, 2, 0x54, 0xc, 2, 1),
	PIN_FIELD_BASE(17, 21, 2, 0x54, 0xc, 21, 1),
	PIN_FIELD_BASE(22, 25, 3, 0x30, 0xc, 0, 1),
	PIN_FIELD_BASE(26, 28, 3, 0x30, 0xc, 5, 1),
	PIN_FIELD_BASE(29, 29, 3, 0x30, 0xc, 9, 1),
	PIN_FIELD_BASE(30, 30, 3, 0x30, 0xc, 11, 1),
	PIN_FIELD_BASE(31, 31, 3, 0x30, 0xc, 10, 1),
	PIN_FIELD_BASE(32, 32, 3, 0x30, 0xc, 8, 1),
	PIN_FIELD_BASE(33, 33, 3, 0x30, 0xc, 4, 1),
	PIN_FIELD_BASE(34, 34, 3, 0x30, 0xc, 12, 1),
	/* 35 ~ 40 doesn't have SMT (these are shared with MIPI-CSI#2) */
	PIN_FIELD_BASE(41, 41, 2, 0x54, 0xc, 18, 1),
	PIN_FIELD_BASE(42, 42, 2, 0x54, 0xc, 20, 1),
	PIN_FIELD_BASE(43, 43, 2, 0x54, 0xc, 17, 1),
	PIN_FIELD_BASE(44, 44, 2, 0x54, 0xc, 16, 1),
	PIN_FIELD_BASE(45, 45, 2, 0x54, 0xc, 15, 1),
	PIN_FIELD_BASE(46, 46, 2, 0x54, 0xc, 14, 1),
	PIN_FIELD_BASE(47, 47, 2, 0x54, 0xc, 13, 1),
	PIN_FIELD_BASE(48, 48, 2, 0x54, 0xc, 12, 1),
	PIN_FIELD_BASE(49, 49, 2, 0x54, 0xc, 11, 1),
	PIN_FIELD_BASE(50, 50, 2, 0x54, 0xc, 10, 1),
	PIN_FIELD_BASE(51, 51, 2, 0x54, 0xc, 19, 1),
	PIN_FIELD_BASE(52, 57, 4, 0x54, 0xc, 0, 1),
	PIN_FIELD_BASE(58, 58, 4, 0x54, 0xc, 14, 1),
	PIN_FIELD_BASE(59, 59, 1, 0x54, 0xc, 6, 1),
	PIN_FIELD_BASE(60, 60, 1, 0x54, 0xc, 8, 1),
	PIN_FIELD_BASE(61, 61, 4, 0x54, 0xc, 15, 1),
	PIN_FIELD_BASE(62, 62, 1, 0x54, 0xc, 9, 1),
	PIN_FIELD_BASE(63, 63, 1, 0x54, 0xc, 11, 1),
	PIN_FIELD_BASE(64, 65, 1, 0x54, 0xc, 4, 1),
	PIN_FIELD_BASE(66, 66, 4, 0x54, 0xc, 11, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x54, 0xc, 7, 1),
	PIN_FIELD_BASE(68, 68, 4, 0x54, 0xc, 12, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x54, 0xc, 10, 1),
	PIN_FIELD_BASE(70, 70, 4, 0x54, 0xc, 13, 1),
	PIN_FIELD_BASE(71, 76, 4, 0x54, 0xc, 16, 1),
	PIN_FIELD_BASE(77, 78, 2, 0x54, 0xc, 0, 1),
	PIN_FIELD_BASE(79, 92, 1, 0x54, 0xc, 12, 1),
};

static const struct mtk_pin_field_calc mt6580_pin_pullen_range[] = {
	PIN_FIELD_BASE(0, 3, 1, 0x0, 0xc, 0, 1),
	PIN_FIELD_BASE(4, 8, 4, 0x0, 0xc, 0, 1),
	PIN_FIELD_BASE(9, 21, 2, 0x0, 0xc, 2, 1),
	PIN_FIELD_BASE(22, 25, 3, 0x0, 0xc, 0, 1),
	PIN_FIELD_BASE(26, 28, 3, 0x0, 0xc, 5, 1),
	PIN_FIELD_BASE(29, 29, 3, 0x0, 0xc, 9, 1),
	PIN_FIELD_BASE(30, 30, 3, 0x0, 0xc, 11, 1),
	PIN_FIELD_BASE(31, 31, 3, 0x0, 0xc, 10, 1),
	PIN_FIELD_BASE(32, 32, 3, 0x0, 0xc, 8, 1),
	PIN_FIELD_BASE(33, 33, 3, 0x0, 0xc, 4, 1),
	PIN_FIELD_BASE(34, 34, 3, 0x0, 0xc, 12, 1),
	PIN_FIELD_BASE(35, 40, 4, 0xa8, 0xc, 0, 1),
	PIN_FIELD_BASE(58, 58, 4, 0x0, 0xc, 8, 1),
	PIN_FIELD_BASE(59, 60, 1, 0x0, 0xc, 18, 1),
	PIN_FIELD_BASE(61, 61, 4, 0x0, 0xc, 9, 1),
	PIN_FIELD_BASE(62, 63, 1, 0x0, 0xc, 20, 1),
	PIN_FIELD_BASE(66, 66, 4, 0x0, 0xc, 5, 1),
	PIN_FIELD_BASE(68, 68, 4, 0x0, 0xc, 6, 1),
	PIN_FIELD_BASE(70, 70, 4, 0x0, 0xc, 7, 1),
	PIN_FIELD_BASE(71, 76, 4, 0x0, 0xc, 10, 1),
	PIN_FIELD_BASE(77, 78, 2, 0x0, 0xc, 0, 1),
	PIN_FIELD_BASE(79, 92, 1, 0x0, 0xc, 4, 1),

	#if 0
	/* These are done differently! */
	PIN_FIELD_BASE(41, 41, 2, 0x30, 0xc, 8, 1),
	PIN_FIELD_BASE(42, 42, 2, 0x30, 0xc, 10, 1),
	PIN_FIELD_BASE(43, 43, 2, 0x30, 0xc, 7, 1),
	PIN_FIELD_BASE(44, 44, 2, 0x30, 0xc, 6, 1),
	PIN_FIELD_BASE(45, 45, 2, 0x30, 0xc, 5, 1),
	PIN_FIELD_BASE(46, 46, 2, 0x30, 0xc, 4, 1),
	PIN_FIELD_BASE(47, 47, 2, 0x30, 0xc, 3, 1),
	PIN_FIELD_BASE(48, 48, 2, 0x30, 0xc, 2, 1),
	PIN_FIELD_BASE(49, 49, 2, 0x30, 0xc, 1, 1),
	PIN_FIELD_BASE(50, 50, 2, 0x30, 0xc, 0, 1),
	PIN_FIELD_BASE(51, 51, 2, 0x30, 0xc, 9, 1),
	PIN_FIELD_BASE(52, 57, 4, 0x30, 0xc, 0, 1),
	PIN_FIELD_BASE(64, 65, 1, 0x30, 0xc, 0, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x30, 0xc, 2, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x30, 0xc, 3, 1),
	#endif
};

static const struct mtk_pin_field_calc mt6580_pin_pullsel_range[] = {
	PIN_FIELD_BASE(0, 3, 1, 0xc, 0xc, 0, 1),
	PIN_FIELD_BASE(4, 8, 4, 0xc, 0xc, 0, 1),
	PIN_FIELD_BASE(9, 21, 2, 0xc, 0xc, 2, 1),
	PIN_FIELD_BASE(22, 25, 3, 0xc, 0xc, 0, 1),
	PIN_FIELD_BASE(26, 28, 3, 0xc, 0xc, 5, 1),
	PIN_FIELD_BASE(29, 29, 3, 0xc, 0xc, 9, 1),
	PIN_FIELD_BASE(30, 30, 3, 0xc, 0xc, 11, 1),
	PIN_FIELD_BASE(31, 31, 3, 0xc, 0xc, 10, 1),
	PIN_FIELD_BASE(32, 32, 3, 0xc, 0xc, 8, 1),
	PIN_FIELD_BASE(33, 33, 3, 0xc, 0xc, 4, 1),
	PIN_FIELD_BASE(34, 34, 3, 0xc, 0xc, 12, 1),
	PIN_FIELD_BASE(35, 40, 4, 0xb4, 0xc, 0, 1),
	PIN_FIELD_BASE(58, 58, 4, 0xc, 0xc, 8, 1),
	PIN_FIELD_BASE(61, 61, 4, 0xc, 0xc, 9, 1),
	PIN_FIELD_BASE(66, 66, 4, 0xc, 0xc, 5, 1),
	PIN_FIELD_BASE(68, 68, 4, 0xc, 0xc, 6, 1),
	PIN_FIELD_BASE(70, 70, 4, 0xc, 0xc, 7, 1),
	PIN_FIELD_BASE(71, 76, 4, 0xc, 0xc, 10, 1),
	PIN_FIELD_BASE(77, 78, 2, 0xc, 0xc, 0, 1),
	PIN_FIELD_BASE(79, 92, 1, 0xc, 0xc, 4, 1),

	#if 0
	/* These are done differently! */
	PIN_FIELD_BASE(41, 41, 2, 0x18, 0xc, 8, 1),
	PIN_FIELD_BASE(42, 42, 2, 0x18, 0xc, 10, 1),
	PIN_FIELD_BASE(43, 43, 2, 0x18, 0xc, 7, 1),
	PIN_FIELD_BASE(44, 44, 2, 0x18, 0xc, 6, 1),
	PIN_FIELD_BASE(45, 45, 2, 0x18, 0xc, 5, 1),
	PIN_FIELD_BASE(46, 46, 2, 0x18, 0xc, 4, 1),
	PIN_FIELD_BASE(47, 47, 2, 0x18, 0xc, 3, 1),
	PIN_FIELD_BASE(48, 48, 2, 0x18, 0xc, 2, 1),
	PIN_FIELD_BASE(49, 49, 2, 0x18, 0xc, 1, 1),
	PIN_FIELD_BASE(50, 50, 2, 0x18, 0xc, 0, 1),
	PIN_FIELD_BASE(51, 51, 2, 0x18, 0xc, 9, 1),
	PIN_FIELD_BASE(52, 57, 4, 0x18, 0xc, 0, 1),
	PIN_FIELD_BASE(64, 65, 1, 0x18, 0xc, 0, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x18, 0xc, 2, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x18, 0xc, 3, 1),
	#endif
};

static const struct mtk_pin_field_calc mt6580_pin_ies_range[] = {
	PIN_FIELD_BASE(0, 3, 1, 0x3c, 0xc, 0, 1),
	PIN_FIELD_BASE(4, 8, 4, 0x3c, 0xc, 6, 1),
	PIN_FIELD_BASE(9, 16, 2, 0x3c, 0xc, 2, 1),
	PIN_FIELD_BASE(17, 21, 2, 0x3c, 0xc, 21, 1),
	PIN_FIELD_BASE(22, 25, 3, 0x18, 0xc, 0, 1),
	PIN_FIELD_BASE(26, 28, 3, 0x18, 0xc, 5, 1),
	PIN_FIELD_BASE(29, 29, 3, 0x18, 0xc, 9, 1),
	PIN_FIELD_BASE(30, 30, 3, 0x18, 0xc, 11, 1),
	PIN_FIELD_BASE(31, 31, 3, 0x18, 0xc, 10, 1),
	PIN_FIELD_BASE(32, 32, 3, 0x18, 0xc, 8, 1),
	PIN_FIELD_BASE(33, 33, 3, 0x18, 0xc, 4, 1),
	PIN_FIELD_BASE(34, 34, 3, 0x18, 0xc, 12, 1),
	PIN_FIELD_BASE(35, 40, 4, 0xc0, 0xc, 0, 1),
	PIN_FIELD_BASE(41, 41, 2, 0x3c, 0xc, 18, 1),
	PIN_FIELD_BASE(42, 42, 2, 0x3c, 0xc, 20, 1),
	PIN_FIELD_BASE(43, 43, 2, 0x3c, 0xc, 17, 1),
	PIN_FIELD_BASE(44, 44, 2, 0x3c, 0xc, 16, 1),
	PIN_FIELD_BASE(45, 45, 2, 0x3c, 0xc, 15, 1),
	PIN_FIELD_BASE(46, 46, 2, 0x3c, 0xc, 14, 1),
	PIN_FIELD_BASE(47, 47, 2, 0x3c, 0xc, 13, 1),
	PIN_FIELD_BASE(48, 48, 2, 0x3c, 0xc, 12, 1),
	PIN_FIELD_BASE(49, 49, 2, 0x3c, 0xc, 11, 1),
	PIN_FIELD_BASE(50, 50, 2, 0x3c, 0xc, 10, 1),
	PIN_FIELD_BASE(51, 51, 2, 0x3c, 0xc, 19, 1),
	PIN_FIELD_BASE(52, 57, 4, 0x3c, 0xc, 0, 1),
	PIN_FIELD_BASE(58, 58, 4, 0x3c, 0xc, 14, 1),
	PIN_FIELD_BASE(59, 59, 1, 0x3c, 0xc, 6, 1),
	PIN_FIELD_BASE(60, 60, 1, 0x3c, 0xc, 8, 1),
	PIN_FIELD_BASE(61, 61, 4, 0x3c, 0xc, 15, 1),
	PIN_FIELD_BASE(62, 62, 1, 0x3c, 0xc, 9, 1),
	PIN_FIELD_BASE(63, 63, 1, 0x3c, 0xc, 11, 1),
	PIN_FIELD_BASE(64, 65, 1, 0x3c, 0xc, 4, 1),
	PIN_FIELD_BASE(66, 66, 4, 0x3c, 0xc, 11, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x3c, 0xc, 7, 1),
	PIN_FIELD_BASE(68, 68, 4, 0x3c, 0xc, 12, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x3c, 0xc, 10, 1),
	PIN_FIELD_BASE(70, 70, 4, 0x3c, 0xc, 13, 1),
	PIN_FIELD_BASE(71, 76, 4, 0x3c, 0xc, 16, 1),
	PIN_FIELD_BASE(77, 78, 2, 0x3c, 0xc, 0, 1),
	PIN_FIELD_BASE(79, 92, 1, 0x3c, 0xc, 12, 1),
};

static const struct mtk_pin_reg_calc mt6580_reg_cals[PINCTRL_PIN_REG_MAX] = {
	[PINCTRL_PIN_REG_MODE] = MTK_RANGE(mt6580_pin_mode_range),
	[PINCTRL_PIN_REG_DIR] = MTK_RANGE(mt6580_pin_dir_range),
	[PINCTRL_PIN_REG_DI] = MTK_RANGE(mt6580_pin_di_range),
	[PINCTRL_PIN_REG_DO] = MTK_RANGE(mt6580_pin_do_range),
	[PINCTRL_PIN_REG_SMT] = MTK_RANGE(mt6580_pin_smt_range),
	[PINCTRL_PIN_REG_PULLEN] = MTK_RANGE(mt6580_pin_pullen_range),
	[PINCTRL_PIN_REG_PULLSEL] = MTK_RANGE(mt6580_pin_pullsel_range),
	[PINCTRL_PIN_REG_IES] = MTK_RANGE(mt6580_pin_ies_range),
};

static const char * const mt6580_pinctrl_register_base_names[] = {
	"gpio", "iocfg_t", "iocfg_b", "iocfg_l", "iocfg_r",
};

static const struct mtk_eint_hw mt6580_eint_hw = {
	.port_mask = 0,
	.ports     = 1,
	.ap_num    = 26,
	.db_cnt    = 26,
};

static const struct mtk_pin_soc mt6580_data = {
	.reg_cal = mt6580_reg_cals,
	.pins = mtk_pins_mt6580,
	.npins = ARRAY_SIZE(mtk_pins_mt6580),
	.ngrps = ARRAY_SIZE(mtk_pins_mt6580),
	.eint_hw = &mt6580_eint_hw,
	.gpio_m = 0,
	.base_names = mt6580_pinctrl_register_base_names,
	.nbase_names = ARRAY_SIZE(mt6580_pinctrl_register_base_names),
	.bias_set_combo = mtk_pinconf_bias_set_combo,
	.bias_get_combo = mtk_pinconf_bias_get_combo,
};

static const struct of_device_id mt6580_pinctrl_of_match[] = {
	{ .compatible = "mediatek,mt6580-pinctrl", .data = &mt6580_data },
	{ /* sentinel */ }
};

static struct platform_driver mt6580_pinctrl_driver = {
	.driver = {
		.name = "mt6580-pinctrl",
		.of_match_table = mt6580_pinctrl_of_match,
	},
	.probe = mtk_paris_pinctrl_probe,
};

static int __init mt6580_pinctrl_init(void)
{
	return platform_driver_register(&mt6580_pinctrl_driver);
}
arch_initcall(mt6580_pinctrl_init);

MODULE_DESCRIPTION("Mediatek MT6580 pinctrl driver");
MODULE_LICENSE("GPLv2");
