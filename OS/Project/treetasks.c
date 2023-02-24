//including necessary header files
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>

//module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Srinandan A");
MODULE_DESCRIPTION("Listing all tasks in a tree using dfs traversal technique");
MODULE_VERSION("0.1");

//function for traversal of the tree of tasks
void dfs(struct task_struct *task)
{
	//initializing head pointer and child pointer
	struct task_struct *child;
	struct list_head *head;
	//code to print the pid, name and state of each of the tasks in a list
	list_for_each(head, &task->children) 
	{
		child = list_entry(head, struct task_struct, sibling);
		printk(KERN_INFO "[pid: %d] [pname: %s] [state: %ld]\n",child->pid, child->comm, child->state);
		//calling dfs function for next child
		dfs(child);
	}	
}

//function to load module into the kernel
int tree_tasks_init(void)
{
	printk(KERN_INFO "Loading module\n");
	dfs(&init_task);
	return 0;
}	

//function to unload module out of the kernel
void tree_tasks_exit(void)
{
	printk(KERN_INFO "Removing module\n");
}

//inbuilt functions for loading and unloading module
module_init(tree_tasks_init);
module_exit(tree_tasks_exit);

