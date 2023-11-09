#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/errno.h>
#include "hello1.h"

MODULE_AUTHOR("Mikholat Evgen <miholatevgen@gmail.com>");
MODULE_DESCRIPTION("hello2 module consist of count variable, init and exit methods");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0644);
MODULE_PARM_DESC(count, "Скільки разів вивести рядок 'Hello, world!'");

static int __init hello2_init(void)
{
	pr_info("hello2 module STARTED\n");

	if (count == 0 || (count >= 5 && count <= 10)) {
		pr_warn("WARNING: Невірне значення параметра.\n");
	} else if (count > 10) {
		pr_err("ERROR: Невірне значення параметра. Модуль не завантажено.\n");
		return -EINVAL;
	}

	print_hello(count);

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("hello2 module FINISHED\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

MODULE_ALIAS("hello2");
