# Pesquisa de uma string numa substring

## Pesquisa exaustiva ou Bruteforce

- O algoritmo efetua a pesquisa como única operação

## Pesquisa que evita Backup (exemplo: KMP)

- Há uma fase de pre-processamento tipicamente do padrão (Fase 1).

- Fase 2 efetua-se a pesquisa usando um modelo de padrão obtido na fase 1.

# KMP (Knuth Morris Pratt)

Abordagem baseada numa máquina de estados deterministica(DFA)

Fase 1: ~M
Fase 2: ~N
Total: ~(M . R + N)




