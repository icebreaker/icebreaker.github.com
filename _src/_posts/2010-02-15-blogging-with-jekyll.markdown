--- 
layout: post
title: Blogging with Jekyll
tags: [blog, jekyll, vim] 
---

My 'editor' trio:

* VIM
* Gedit
* QtCreator

Here is my .vimrc for those who might want to take a look.

{% highlight vim %}
set nowrap
set complete-=i
set wildmenu
set fileformats=unix,mac,dos
set nocp
set keymodel=startsel
set laststatus=2
set novisualbell
set number
set report=0
set lazyredraw
set listchars=tab:\|\ ,trail:.,extends:>,precedes:<,eol:$ 
set autoindent
set cindent
set noexpandtab
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set smarttab
set showmatch
set nohlsearch
set incsearch
set nocompatible
set backspace=indent,eol,start
set diffopt+=iwhite
set hidden
set nostartofline
set shortmess=as
set showcmd
set ttyfast
set mouse=a

colorscheme zenburn
filetype plugin on
filetype plugin indent on
filetype on
syntax on

" Word Completion
function! Tab_Or_Complete()
	if col('.')>1 && strpart( getline('.'), col('.')-2, 3 ) =~ '^\w'
		return "\<C-N>"
	else
		return "\<Tab>"
	endif
endfunction
inoremap <Tab> <C-R>=Tab_Or_Complete()<CR>
set dictionary="/usr/share/dict/words"

" Default Markdown Blog Post Template (to be used with Jekyll)
autocmd BufNewFile *.markdown silent! 0r $HOME/.vim/templates/markdown.vim
{% endhighlight %}

I would like to highlight two things:

1. Word Completion
2. Default Markdown Blog Post Template

I don't think that the Word Completion feature needs any further explanations, but for the Markdown Blog Post template it worth mentioning that whenever I
create **somefile.markdown** it will automatically get filled with the contents of the template file residing in **~/.vim/templates/markdown.vim** .
