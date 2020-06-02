#!/bin/bash


FILENAME=( "Bilinear" "Bilinear")

for i in ${FILENAME[@]}; 
do  
    echo XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    echo $i
    echo XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    dia $i.dia -t mp --export=$i.mp

    echo "\documentclass{article}
    \pagestyle{empty}
    \usepackage{graphicx}
    \begin{document}
    \includegraphics[width=\textwidth]{"$i.1"}
    \end{document}" > temporallatex-$i.tex

    mpost  -tex=latex -interaction=nonstopmode $i.mp
    latex temporallatex-$i.tex
    dvips -E -o temporallatex-$i.eps temporallatex-$i

    rm -f $i.log
    rm -f $i.mpx
    rm -f $i.mp
    rm -f $i.1

    rm -f temporallatex-$i.tex
    rm -f temporallatex-$i.aux  
    rm -f temporallatex-$i.log  
    rm -f temporallatex-$i.dvi

    convert -density 400 temporallatex-$i.eps -flatten $i.png

    rm -f temporallatex-$i.eps

done




