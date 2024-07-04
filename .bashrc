x#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias grep='grep --color=auto'
alias shut='shutdown -h now'
alias pacs='sudo pacman -S'
alias pac='sudo pacman'
alias v='sudo vim'
alias conf='cd ~/.config/'
alias i3c='sudo vim ~/.config/i3/config'
alias picc='sudo vim ~/.config/picom/picom.conf'
alias cd..='cd ..'
PS1='[\u@\h \W]\$ '

eval "$(starship init bash)"

eval "$(starship init bash)"
