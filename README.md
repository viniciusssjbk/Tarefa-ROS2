# Tarefa-ROS2
Um projeto com nó publisher e um nó subscriber que se comunicam através de um tópico

Rodar o ROS2  ---> source ~/.bashrc

verificar as fontes --> printenv | grep -i ROS

id ou dominios --> ROS_DOMAIN_ID

executar os pacotes --> ros2 run <package_name> <executable_name>

listar os nos --> ros2 node list

nomear os nós --> ros2 run <package_name> <executable_name>--ros-args --remap __node:= <nome que você queira usar>

acessar informações dos nos --> ros2 node info /<node_name>

ver em graficos as ligações dos nos e dos topicos --> ros2 run rqt_graph rqt_graph (circulos sao os nos e as setas sao os topicos)

lista de topicos --> ros2 topic list

lista de topicos com suas ligações --> ros2 topic list -t

ver as informações que o topico esta passando --> ros2 topic echo /<nome do topico>

ver informação do topico --> ros2 topic info /<nome do topico> 

ver os valores que um topico está esperando --> ros2 interface show <nome do topico>

criar uma mensagem para o topico --> ros2 topic pub <topic_name> <msg_type> '<{mensagem}>' #para ter um fluxo constante do comando e caso queira so uma vez colocar assim 'topic pub --once'

achar o topico de um tipo especifico --> ros2 topic find <topic_type>

listar os serviços --> ros2 service list


1. nós são os programas
2. topicos é a ligação entre nós onde um nó publica uma mensagem e pode ser enviado para varios outros nós
3. serviços são ligações de nós onde um nó solicita e o outro nó responde, porem existe o tipo de nó que nem solicita e nem recebe resposta

achar o tipo de serviço --> ros2 service type <service_name> ou ros2 service -t para mostrar junto os tipos dele
valores: empty = não recebe e nem envia solicitação 

mostrar tipo de socilitação(em cima do ---) e da resposta(em baixo ---) --> ros2 interface show <type_name>

fazer uma chamada pelo serviço --> ros2 service call <service_name> <service_type> <arguments>
