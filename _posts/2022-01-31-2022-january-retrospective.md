---
layout: post
title: 2022 January Retrospective
propaganda: 6
music: f0oUuhrXGok
topic: retrospective
---
2022 January Retrospective
==========================
Holy-molly, it's the end of January. Time truly flies by these days, more so
than used to be. At least that's how it all feels to me; or perhaps I am just
getting old and gray, which of course wouldn't be surprising. Nobody can stay
young forever, not even me the great code gardener of the gods.

But on a more serious note, I did promise at least one post per month and here
I am fulfilling that promise. I think that doing it more of a monthly-
retrospective-almost-newsletter-style might actually work and force me to sit
down and write, rather than just keep postponing it indefinitely by finding
various excuses.

While January was truly a very very busy month for me work wise, I didn't get
much done on my personal projects; in fact I got done even less than I hoped
that I would find the time to do so.

But, I did start the work in earnest so to speak on `OLEN Build` and started
sketching out the `OLEN Games Toolchain` as a whole as well. There isn't
anything that I could write in length about just yet, but I managed to get the
proverbial ball rolling in the right direction. Or at least that's what I
would like to believe.

However, there's one detail that I will share, even though it's not going to
be the most exciting thing known to man. What is it, you might ask?

Well, I decided to use [OpenMP][openmp] for the parallel-execution aspect of
`OLEN Build`. How well will this turn out to be in practice, that remains to
be seen, but even if it turns into an utter disaster, the project is still in
a very early state so it should be easy-peasy to swap it out and do it the old
fashioned manual way without relying on [OpenMP][openmp].

In its crudest incarnation, one can imagine something like the code snippet
below.

```c
const char *cmds[] = {
	"cc -O2 -c test0.c -o test0.o",
	"cc -O2 -c test1.c -o test1.o",
	...
	NULL
};

...

#pragma omp parallel for shared(cmds) schedule(runtime) ordered
for(const char **cmd = cmds; *cmd != NULL; cmd++)
{
	char *output = execute_cmd(*cmd);
#pragma omp ordered
	puts(output);
	free(output);
}

...
```

Not too shabby, right? Of course one mustn't forget to compile with `-fopenmp`,
but that's a small price to pay.

At any rate, that's pretty much all I got to share for the time being. See you
at the end of next month, which also happens to be the month when I do `age++`.

[openmp]: https://www.openmp.org/
