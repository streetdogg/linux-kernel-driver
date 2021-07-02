/**
 * MIT License
 * 
 * Copyright (c) 2021 Piyush Itankar <pitankar@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

/* Paramaters to be input during load time */
static char *msg = "Hello, world!";   /* Greeting message */
static int times = 1;               /* No of times to iterate the message */
static int key[4] = {0, 0, 0, 0};   /* Some random key */

/* Module parameter registration and description */
module_param(msg, charp, S_IRUGO);
MODULE_PARM_DESC(msg, "Custom greeting message");

module_param(times, int, S_IRUGO);
MODULE_PARM_DESC(times, "Number of times the greeting message needs to be printed");

module_param_array(key, int, NULL, S_IWUSR|S_IRUSR);
MODULE_PARM_DESC(key, "Random 4 digit key, used for nothing :P");

/* Module initialization */
static int __init fake_module_init(void) {
    int i;

    printk(KERN_INFO "Fake module init!\n");

    for (i=0; i<times; i++)
        printk(KERN_INFO "%s\n", msg);
    
    printk(KERN_INFO "Key: %d%d%d%d\n", key[0], key[1], key[2], key[3]);

    return 0;
}

/* Module cleanup */
static void __exit fake_module_exit(void) {
    printk(KERN_INFO "Good bye, cruel world!\n");
}

module_init(fake_module_init);
module_exit(fake_module_exit);

MODULE_AUTHOR("Piyush Itankar <pitankar@gmail.com>");
MODULE_LICENSE("GPL");