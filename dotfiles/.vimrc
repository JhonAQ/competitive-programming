se si aw ai ru nu rnu ts=4 sw=4 et noeb bg=dark cul cin
sy on | im jk <ESC>
nm <F8> :bo term g++ -Wall -Wshadow -Wextra -Wconversion -Wfatal-errors -g -std=gnu++20 %<CR>
nm <F9> :bo term sh -c "./a.out < %:r<CR>"
nm <space>w :w<CR>
nm <space>q :q<CR>
au BufNewFile *.cpp 0r ~/competitive-programming/dotfiles/template.cpp
