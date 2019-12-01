# gnuplot file
# generates the graph for cocktail sort and Bubblesort

set term png                        # will produce .png output
set output "graficoComparacao.png"  # output to any filename.png you want
set grid                            # grid background
set title 'Cocktail x Bubble'       # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'          # y-axis label
set multiplot                       # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'BubbleIterativoLista.txt' with linespoints title 'BubbleIterativoLista', 'BubbleIterativoVetor.txt' with linespoints title 'BubbleIterativoVetor','BubbleSortRecursivoVetor.txt' with linespoints title 'BubbleSortRecursivoVetor','HeapSortIterativoVetor.txt' with linespoints title 'HeapSortIterativoVetor','HeapSortRecursivoVetor.txt' with linespoints title 'HeapSortRecursivoVetor','insertionsortIterativoLista.txt' with linespoints title 'insertionsortIterativoLista','InsertSortIterativoVetor.txt' with linespoints title 'InsertSortIterativoVetor','InsertSortRecursivoVetor.txt' with linespoints title 'InsertSortRecursivoVetor','MergeSortIterativoVetor.txt' with linespoints title 'MergeSortIterativoVetor','MergeSortRecursivoVetor.txt' with linespoints title 'MergeSortRecursivoVetor','QuickSortIterativoVetor.txt' with linespoints title 'QuickSortIterativoVetor','QuickSortRecursivoVetor.txt' with linespoints title 'QuickSortRecursivoVetor','selectionsortLista.txt' with linespoints title 'selectionsortLista','SelectSortIterativoVetor.txt' with linespoints title 'SelectSortIterativoVetor','SelectSortRecursivoVetor.txt' with linespoints title 'SelectSortRecursivoVetor'

plot  'BubbleSortRecursivoVetor.txt' with linespoints title 'BubbleSortRecursivoVetor','HeapSortRecursivoVetor.txt' with linespoints title 'HeapSortRecursivoVetor','InsertSortRecursivoVetor.txt' with linespoints title 'InsertSortRecursivoVetor','MergeSortRecursivoVetor.txt' with linespoints title 'MergeSortRecursivoVetor','QuickSortRecursivoVetor.txt' with linespoints title 'QuickSortRecursivoVetor','SelectSortRecursivoVetor.txt' with linespoints title 'SelectSortRecursivoVetor'

plot 'BubbleIterativoLista.txt' with linespoints title 'BubbleIterativoLista', 'BubbleIterativoVetor.txt' with linespoints title 'BubbleIterativoVetor','HeapSortIterativoVetor.txt' with linespoints title 'HeapSortIterativoVetor','insertionsortIterativoLista.txt' with linespoints title 'insertionsortIterativoLista','InsertSortIterativoVetor.txt' with linespoints title 'InsertSortIterativoVetor','MergeSortIterativoVetor.txt' with linespoints title 'MergeSortIterativoVetor','QuickSortIterativoVetor.txt' with linespoints title 'QuickSortIterativoVetor','selectionsortLista.txt' with linespoints title 'selectionsortLista','SelectSortIterativoVetor.txt' with linespoints title 'SelectSortIterativoVetor'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
