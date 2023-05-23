
ifndef BONUS
	SRCCLIENT 		= client.c ft_error.c math_basic.c client_untils.c
	SRCSERVEUR		= serveur.c ft_error.c math_basic.c serveur_untils.c
endif

ifdef BONUS
	SRCCLIENT 		= client_bonus.c ft_error_bonus.c math_basic_bonus.c client_untils_bonus.c
	SRCSERVEUR		= serveur_bonus.c ft_error_bonus.c math_basic_bonus.c serveur_untils_bonus.c
endif

SRCBONUS 	= 
NAMEC 		= client
NAMES		= serveur
NAMEL		= ./LIBFT/libft.a

MAKEFLAGS	= --no-print-directory

#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

all :		${NAMEC} ${NAMES}
			@echo "${WHITEGREEN}PROGRAMME \"${NAMEC}\" ET \"${NAMES}\" PRET POUR EXECUTION !${NEUTRE}"

${NAMEL}:
			@cd LIBFT && make

${NAMEC}: ${NAMEL} ${SRCCLIENT}
			@echo "${BLACKPURPLE}=============== CRÉATION CLIENT ==============${WHITE}" 
			gcc  -Wall -Wextra -Werror  -o ${NAMEC} ${SRCCLIENT} ${NAMEL}
			@echo "${BLACKPURPLE}============= FIN CRÉATION CLIENT ============${NEUTRE}" 

${NAMES}: ${NAMEL} ${SRCSERVEUR}
			@echo "${BLACKPURPLE}============== CRÉATION SERVEUR ==============${WHITE}" 
			gcc  -Wall -Wextra -Werror  -o ${NAMES} ${SRCSERVEUR} ${NAMEL}
			@echo "${BLACKPURPLE}============ FIN CRÉATION SERVEUR ============${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			rm -f ${PO}
			@echo -n "${NEUTRE}"
			@cd LIBFT && make clean

fclean :	clean
			@cd LIBFT && make fclean
			@echo -n "${BLACKRED}"
			rm -f ${NAMEC} ${NAMES}
			@echo -n "${NEUTRE}"

bonus :
			@make BONUS=42

re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus