#include "bsq.h"

void print_map(t_map *map)
{
    for(int i=0; i < map->row; i++)
        fprintf(stdout,"%s\n",map->grid[i]);
}

void free_map(t_map *map)
{
    if(!map || map->grid) //bbb
        return ;
    for(int i =0; i<map->row; i++)
        free(map->grid[i]);
    free(map->grid);
}

int main_n0(int argc,char **argv)
{
    t_map map;

    map.row=0;
    map.col=0;
    map.grid=NULL;

    if(argc==1)
    {
        if(!read_from_stdin(&map))
        {
            free_map(&map);
            fprintf(stdout, "Error: invalid map\n");
            return(1);
        }
        if(!alg_bsq(&map))
        {
            free_map(&map);
            fprintf(stdout, "Error: malloc error\n");
            return(1);
        }
        print_map(&map);
        free_map(&map);
        return(0);
    }
    if(argc != 2)
    {
        free_map(&map);
        fprintf(stdout, "Error: invalid number of arguments\n");
            return(1);
    }

    if(!read_from_argv(argv[1],&map))
    {
        free_map(&map);
        fprintf(stdout, "Error: invalid map\n");
            return(1);
    }
    if(!alg_bsq(&map))
    {
        free_map(&map);
            fprintf(stdout, "Error: malloc error\n");
            return(1);
    }
     print_map(&map);
        free_map(&map);
    return(0);
}

int main(void)
{
    char *argv_stdin[] = {"bsq", NULL};
    char *argv_invalid_argc[] = {"bsq", "file1", "file2", NULL};
    char *argv_invalid_map[] = {"bsq", "invalid_map.txt", NULL};
    char *argv_valid_map[] = {"bsq", "valid_map.txt", NULL};

    fprintf(stdout, "\n--- TEST 1: argc == 1 (stdin) ---\n");
    bsq_main(1, argv_stdin);

    fprintf(stdout, "\n--- TEST 2: argc != 2 (error) ---\n");
    bsq_main(3, argv_invalid_argc);

    fprintf(stdout, "\n--- TEST 3: argc == 2, invalid map ---\n");
    bsq_main(2, argv_invalid_map);

    fprintf(stdout, "\n--- TEST 4: argc == 2, valid map ---\n");
    bsq_main(2, argv_valid_map);

    return (0);
}
/*
Good catch — they’re **not special files at all** 👍
That part was just *placeholders*, which I should’ve explained more clearly.

Let’s break it down cleanly.

---

## What `file1` / `file2` actually are

In this line:

```c
char *argv_invalid_argc[] = {"bsq", "file1", "file2", NULL};
```

* `"file1"` and `"file2"` are **dummy strings**
* They **do not need to exist**
* They’re only there to:

  * Make `argc == 3`
  * Trigger this branch:

```c
if (argc != 2)
{
    fprintf(stdout, "Error: invalid number of arguments\n");
}
```

So this test is **only about argument count**, not files.

---

## Same for `"invalid_map.txt"` and `"valid_map.txt"`

```c
char *argv_invalid_map[] = {"bsq", "invalid_map.txt", NULL};
char *argv_valid_map[]   = {"bsq", "valid_map.txt", NULL};
```

These **ARE expected to be real files** if you want meaningful behavior:

* `invalid_map.txt`

  * Exists but has bad map format
  * OR doesn’t exist at all → `read_from_argv()` fails

* `valid_map.txt`

  * Properly formatted BSQ map
  * Makes the program reach the success path

---

## If you want ZERO real files (pure logic testing)

You can mock `read_from_argv` like this:

```c
int read_from_argv(char *path, t_map *map)
{
    (void)map;
    if (!strcmp(path, "invalid"))
        return (0);
    return (1);
}
```

Then use:

```c
char *argv_invalid_map[] = {"bsq", "invalid", NULL};
char *argv_valid_map[]   = {"bsq", "valid", NULL};
```

No filesystem needed 💡

---

## TL;DR

| Name              | Meaning                               |
| ----------------- | ------------------------------------- |
| `file1`, `file2`  | Fake arguments to trigger `argc != 2` |
| `invalid_map.txt` | File path meant to fail               |
| `valid_map.txt`   | File path meant to succeed            |

Nothing magical — just argument simulation.

If you want, I can also show:

* How to **mock stdin input**
* How to build a **minimal valid BSQ map file**
* How to test this with `valgrind`

Just tell me 🙂


*/

//*********************************************** */
//*********************************************** */
//*********************************************** */
//*********************************************** */


// int main(int argc, char **argv)
// {
//     // t_map map;

//     // map.row=0;
//     // map.col=0;
//     // map.grid=NULL;
//     t_map map;

//     if (argc == 1)
//     {
//         if (!read_from_stdin(&map))
//         {
//             fprintf(stdout, "Error: invalid map\n");
//             return (1);
//         }
//     }
//     else if (argc == 2)
//     {
//         if (!read_from_argv(argv[1], &map))
//         {
//             fprintf(stdout, "Error: invalid map\n");
//             return (1);
//         }
//     }
//     else
//     {
//         fprintf(stdout, "Error: invalid number of arguments\n");
//         return (1);
//     }

//     if (!alg_bsq(&map))
//     {
//         free_map(&map);
//         fprintf(stdout, "Error: malloc error\n");
//         return (1);
//     }

//     print_map(&map);
//     free_map(&map);
//     return (0);
// }
/*

Got it 👍
You want **test cases that hit every `if / else if` path**, using a **new `main`**, and the **original `main` renamed** so it can be called from tests.

Below is a clean, realistic way to do that in C.

---

## 1️⃣ Rename the original `main`

Rename your original `main` to something like `bsq_main`:

```c
int bsq_main(int argc, char **argv)
{
    t_map map;

    map.row = 0;
    map.col = 0;
    map.grid = NULL;

    if (argc == 1)
    {
        if (!read_from_stdin(&map))
        {
            free_map(&map);
            fprintf(stdout, "Error: invalid map\n");
            return (1);
        }
        if (!alg_bsq(&map))
        {
            free_map(&map);
            fprintf(stdout, "Error: malloc error\n");
            return (1);
        }
        print_map(&map);
        free_map(&map);
        return (0);
    }

    if (argc != 2)
    {
        free_map(&map);
        fprintf(stdout, "Error: invalid number of arguments\n");
        return (1);
    }

    if (!read_from_argv(argv[1], &map))
    {
        free_map(&map);
        fprintf(stdout, "Error: invalid map\n");
        return (1);
    }

    if (!alg_bsq(&map))
    {
        free_map(&map);
        fprintf(stdout, "Error: malloc error\n");
        return (1);
    }

    print_map(&map);
    free_map(&map);
    return (0);
}
```

---

## 2️⃣ Test `main` that triggers **ALL branches**

This `main` manually simulates different `argc / argv` combinations so **every conditional path executes**.

```c
int main(void)
{
    char *argv_stdin[] = {"bsq", NULL};
    char *argv_invalid_argc[] = {"bsq", "file1", "file2", NULL};
    char *argv_invalid_map[] = {"bsq", "invalid_map.txt", NULL};
    char *argv_valid_map[] = {"bsq", "valid_map.txt", NULL};

    fprintf(stdout, "\n--- TEST 1: argc == 1 (stdin) ---\n");
    bsq_main(1, argv_stdin);

    fprintf(stdout, "\n--- TEST 2: argc != 2 (error) ---\n");
    bsq_main(3, argv_invalid_argc);

    fprintf(stdout, "\n--- TEST 3: argc == 2, invalid map ---\n");
    bsq_main(2, argv_invalid_map);

    fprintf(stdout, "\n--- TEST 4: argc == 2, valid map ---\n");
    bsq_main(2, argv_valid_map);

    return (0);
}
```

---

## 3️⃣ Which branches are covered

| Test       | Condition hit                     |
| ---------- | --------------------------------- |
| Test 1     | `argc == 1` → stdin path          |
| Test 2     | `argc != 2` error                 |
| Test 3     | `read_from_argv` fails            |
| Test 4     | success path                      |
| (implicit) | `alg_bsq` failure if malloc fails |

If you want to **force `alg_bsq` failure**, you can temporarily mock it:

```c
int alg_bsq(t_map *map)
{
    (void)map;
    return (0); // force malloc error
}
```

---

## 4️⃣ Why this approach is correct

* ✅ No need to recompile multiple times
* ✅ Deterministic test coverage
* ✅ Matches how unit tests simulate CLI input
* ✅ Clean separation between production code and test code

---

If you want, I can also:

* Add **mock versions** of `read_from_stdin` / `read_from_argv`
* Convert this into a **42-style tester**
* Or show how to test this with **Makefile targets**

Just say the word 👌

*/

