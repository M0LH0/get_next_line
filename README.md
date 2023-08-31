<h1 align="left">Libft</h1>
<div><img align="right" src="https://game.42sp.org.br/static/assets/achievements/get_next_linem.png"/> <h4>The second project on the 42sp fundamentals track, Get Next Line, is based on the creation of a function that returns line by line from a file pointed to by a file descriptor, covering topics such as reading and describing files, static variables, dynamic allocation memory, pointers, and more. </h4>
<div> <h3>Get Next Line</h3>

* [`get_next_line.c`](src/get_next_line.c)      [`get_next_line_bonus.c`](src/get_next_line_bonus.c)

<h3>Get Next Line utils</h3>

* [`get_next_line_utils.c`](utils/get_next_line_utils.c)      [`get_next_line_utils_bonus.c`](utils/get_next_line_utils_bonus.c)

<h3>Headers</h3>

 * [`get_next_line.h`](include/get_next_line.h)      [`get_next_line_bonus.h`](include/get_next_line_bonus.h)

</div>
<div>
  <h2>Run the Program</h2>

  * Make sure you clone the repository with the following command:

```
git clone git@github.com:M0LH0/get_next_line.git
```

  * Once cloned, compile the program with the following command (the value of BUFFER_SIZE can be changed if you prefer):

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c src/get_next_line.c utils/get_next_line_utils.c include/get_next_line.h  
```

Running the code, the result should look like the ascii.txt file in the repository, nice ascii image will appear in your terminal :)
</div>
