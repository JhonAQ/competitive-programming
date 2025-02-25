# Fast IO

- Fast IO makes cin/cout faster (as fast as scanf/printf)
- It can be used by adding: 

```cpp
ios::sync_with_stdio(false); cin.tie(NULL);
```

- sync makes 1 - 3 - 2 - 4 output, cin removes the user dialog before inputs
- It removes sync between cout/prinft, and removes sync between cin/cout
- '\n' should be used instead of endl, as endl flushes automatycally (does not apply to interactive problems bc flush)
- Fast IO should not be used for interactive problems, when debugging, and when wrtiting production code
- Use fread and rwrite if I am looking for something even faster (see atached snippets)

## Code Snippet: Input

```cpp
inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) { return EOF; }
	}
	return buf[pos++];
}

int read_int() {
	int x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') { sgn *= -1; }
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
	return x * sgn;
}
}  // namespace Input
```

## Code Snippet: Output

```cpp
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(int x) {
	static char num_buf[100];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
	write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
```
