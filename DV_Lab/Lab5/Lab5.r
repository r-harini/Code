install.packages("igraph")
library(igraph)
adj=as.matrix(read.csv("C:/Code/DV_Lab/Lab5/Adjacency.csv"))
edg=as.matrix(read.csv("C:/Code/DV_Lab/Lab5/Edges.csv"))
dat=read.csv(file.choose(),header=TRUE,sep=',', row.names=1,check.names=FALSE)
m=as.matrix(dat)
net=graph.adjacency(m,mode="undirected",weighted=TRUE,diag=FALSE)
plot.igraph(net,vertex.label=V(net)$name,layout=layout.fruchterman.reingold,
            edge.arrow.size=0.5)
net
V(net)
E(net)
x=adjacent_vertices(net, V(net), mode=c("out", "in", "all", "total"))
degree(net, v = V(net), mode = c("all", "out", "in", "total"), loops = TRUE, normalized = FALSE)

net=set_vertex_attr(net, "Type", index=V(net), c("leap", "nonleap","nonleap","nonleap",
                                                 "leap", "nonleap", "nonleap", "nonleap",
                                                 "leap", "nonleap", "nonleap"))
e=set_edge_attr(net, "Weight", index=V(net), c(1,1,1,1,1,1,1,1,1,5,1))
plot.igraph(net, vertex.label.color="red", vertex.label.dist=0, vertex.label.family="Helvetica",
            vertex.frame.color="yellow", vertex.size=35)
e
nnet=as.directed(net)
plot.igraph(nnet,vertex.label=V(net)$name,layout=layout.fruchterman.reingold,
            edge.arrow.size=0.5)

  newnet=as.directed(net, "arbitrary")
newnet
plot.igraph(newnet, vertex.label.color="red", vertex.label.dist=0, vertex.label.family="Helvetica",
            vertex.frame.color="yellow", vertex.size=35)

get.adjacency(newnet)

d=data.frame(
  In=dgr(newnet, "indegree", undirected = FALSE),
  Out=dgr(newnet, "outdegree", undirected = FALSE))
