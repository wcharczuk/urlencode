#urlencode / urldecode#

A simple (set of) commandline utilities to url encode/decode strings.

_But can't i just write an awk/perl/python script?_

You sure can! I just wanted to see if I could write this in C.


**INSTALLATION**

Run the make file, and make install.

```bash
make; make install
```

This will drop the ```urlencode``` and ```urldecode``` binaries in your ```/usr/local/bin``` directory.


**USAGE**

Either pass in the string as an arument

```bash
urlencode "hello world!"
hello%20world%21⏎ 
```

or pipe some text to it

```bash
echo "hello world!" | urlencode
hello%20world%21⏎
```

or pipe them together because, why not?

```bash
echo "hello world!" | urlencode | urldecode
hello world!⏎
```

That's about it. I am a total newbie when it comes to C, so this is not memory efficient or even recommended to be used, but it was fun to write.

Pull requests welcome!
