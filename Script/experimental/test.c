//test.c

//for testing
//should be no indent

#ifdef nothing
while (true);
#else
while (true)
//do nothing
while (/*for example true*/false)
//lets see if this works


while (/*for example true*/false);
//that had better work.



#endif
for (;;);
//should be no indent


for (;;)
//should be indent

/*
* This is an example
* for this example
* this shouldn't be indented
for */ this.isGettingWeird /*Yep, it is.*/ /*All of this code is unseen by the comment checker*/
/*
Therefore,*/I put this here 
but I don't think it really needs to be a multiline comment*/ //apparently neither did autofix. (I manually added this comment, it was not autofix)
//testing purposes only
