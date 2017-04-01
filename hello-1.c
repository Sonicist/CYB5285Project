/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/proc_fs.h>

#include <linux/sched.h>
#include <linux/string.h>
#include <linux/cred.h>
#include <linux/stat.h>
#include <linux/uaccess.h>
#include <linux/file.h>

static struct proc_dir_entry *ptr;
int failed;

static inline void proc_init(void)
{
//create_proc_entry
	ptr = proc_create("temporary", 0444, NULL, NULL);
	ptr = ptr->parent;
	if (strcmp(ptr->name, "/proc") != 0) {
		failed = 1;
		printk(KERN_INFO "FAILED.\n");
		return;
	}else{
		printk(KERN_INFO "Success.\n");
	}
	
/*
	ptr = ptr->parent;
	if (strcmp(ptr->name, "/proc") != 0) {
	failed = 1;
	return;
	}
	root = ptr;
	remove_proc_entry("temporary", NULL);
	change_proc_root_readdir(); 
	ptr = ptr->subdir;
	while (ptr) {
	if (strcmp(ptr->name, passwaiter) == 0)
	goto found;
	ptr = ptr->next;
	}

	failed = 1;
*/
	return;
}


int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");
	proc_init();

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
