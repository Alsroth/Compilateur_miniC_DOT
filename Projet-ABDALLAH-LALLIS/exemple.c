digraph mon_programme {
node1[shape=ellipse label="i" style=solid color=black]
node3[shape=ellipse label="0" style=solid color=black]
node4[shape=ellipse label=":=" style=solid color=black]
node5[shape=ellipse label="i" style=solid color=black]
node7[shape=ellipse label="10" style=solid color=black]
node8[shape=ellipse label="<" style=solid color=black]
node9[shape=ellipse label="i" style=solid color=black]
node11[shape=ellipse label="i" style=solid color=black]
node13[shape=ellipse label="1" style=solid color=black]
node14[shape=ellipse label="+" style=solid color=black]
node15[shape=ellipse label=":=" style=solid color=black]
node16[shape=ellipse label="i" style=solid color=black]
node18[shape=ellipse label="5" style=solid color=black]
node19[shape=ellipse label="==" style=solid color=black]
node20[shape=box label="BREAK" style=solid color=black]
node21[shape=diamond label="IF" style=solid color=black]
node22[shape=ellipse label="BLOC" style=solid color=black]
node23[shape=ellipse label="FOR" style=solid color=black]
node24[shape=ellipse label="i" style=solid color=black]
node26[shape=septagon label="printd" style=solid color=black]
node27[shape=ellipse label="BLOC" style=solid color=black]
node28[shape=invtrapezium label="int , main" style=solid color=blue]
node28->node27
node27->node26
node26->node24
node27->node23
node23->node22
node22->node21
node21->node20
node21->node19
node19->node18
node19->node16
node23->node15
node15->node14
node14->node13
node14->node11
node15->node9
node23->node8
node8->node7
node8->node5
node23->node4
node4->node3
node4->node1

}
