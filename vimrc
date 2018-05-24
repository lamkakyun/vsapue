""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" vundle settings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim " run time path
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'jiangmiao/auto-pairs' " Insert or delete brackets, parens, quotes in pair.
Plugin 'vim-scripts/taglist.vim'
Plugin 'ervandew/supertab'
Plugin 'vim-airline/vim-airline'
Plugin 'Valloric/YouCompleteMe'
Plugin 'wincent/command-t'
Plugin 'Chiel92/vim-autoformat'
Plugin 'kien/ctrlp.vim'

" Plugin 'tpope/vim-fugitive'  " git tools 

call vundle#end()            " required
filetype plugin indent on    " required

filetype indent on      " load filetype-specific indent files , /usr/local/share/vim/vim80/indent

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" self-define command in vim
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" command Bufferlist ls
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" YouCompleteMe Settings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:ycm_server_python_interpreter='/usr/bin/python2.7'
let g:ycm_global_ycm_extra_conf='~/.vim/.ycm_extra_conf.py'
"let g:syntastic_quiet_messages = {'level': 'warnings'}

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" NERDTree Settings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" map <C-n> :NERDTreeToggle<CR>
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif " close NERDTree when winow closed
let NERDTreeShowLineNumbers=1
let g:NERDTreeIndicatorMapCustom = {
    \ "Modified"  : "✹",
    \ "Staged"    : "✚",
    \ "Untracked" : "✭",
    \ "Renamed"   : "➜",
    \ "Unmerged"  : "═",
    \ "Deleted"   : "✖",
    \ "Dirty"     : "✗",
    \ "Clean"     : "✔︎",
    \ "Unknown"   : "?"
    \ }
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" command-t settings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:CommandTAcceptSelectionMap = '<C-t>'
let g:CommandTAcceptSelectionTabMap = '<CR>'
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General Settings
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nu
colorscheme badwolf         " awesome colorscheme
syntax enable

set tabstop=4 
set softtabstop=4 
set shiftwidth=4
set expandtab " tab are spaces
set smarttab

set showcmd " show cmd in bottom bar
set wildmenu 
set cursorline " highlight current line
set lazyredraw 
set showmatch
set incsearch 
set hlsearch
" set fileformats=unix,dos
"set listchars=tab:>-,trail:-
" set list " show empty characters

"let mapleader=','
let mapleader='.'
" Mapping setting
" map <leader>b :buffers<CR>
map <leader>t :tabnew .<CR>
map <leader>n :NERDTreeToggle<CR>
" map <leader>tl :TListToggle<CR>

map <left> <C-w><left>
map <right> <C-w><right>
map <up> <C-w><up>
map <down> <C-w><down>

map <leader>2 :vsp<CR>
map <leader>d :YcmDiags<CR>
map <leader>y :YcmCompleter<tab>
map <leader>j :YcmCompleter GoTo<CR>
map <leader>o :CommandT<CR>
"map <leader>h :e /home/jet/.vimrc<CR>
map <leader>h :vsp /media/sf_Coding/apue/vimrc<CR>
map <leader>ff :Autoformat<CR>
map <leader>s :CtrlP ./<CR>
map <F2> :bprevious<CR>
map <F3> :bnext<CR>
map <F4> :buffers<CR>

map <F6> :tabprevious<CR>
map <F7> :tabNext<CR>
map <F8> :tabs<CR>
