set term pdf
set output "fig.pdf"
set xlabel "N"
set ylabel "Delta"
plot "datos.txt" u 1:2 w l, "" u 1:3 w p