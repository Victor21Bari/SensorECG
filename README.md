
<h1>Projeto de Monitoramento de Sinais Cardíacos com ECG AD8232 e ESP32</h1>

<h2>Descrição do Funcionamento e Uso</h2>
<p>Este projeto mede sinais cardíacos usando um sensor ECG AD8232 e publica esses dados em tempo real na plataforma Ubidots usando o protocolo MQTT. O sistema é composto por um microcontrolador ESP32, que lê os dados do sensor ECG, processa esses dados para calcular a frequência cardíaca em BPM (batimentos por minuto) e publica os resultados na plataforma Ubidots através de uma conexão WiFi.</p>

<h2>Passos para Reproduzir o Projeto</h2>

<h3>Montagem do Hardware</h3>
<ul>
    <li>Conecte o sensor ECG AD8232 ao ESP32 seguindo o diagrama de pinos.</li>
    <li>Conecte um LED ao ESP32 através de um resistor de 220 ohms.</li>
    <li>Utilize uma protoboard para realizar todas as conexões com jumpers macho-fêmea.</li>
</ul>

<h3>Configuração do Software</h3>
<ul>
    <li>Configure a rede WiFi e as credenciais da plataforma Ubidots no código.</li>
    <li>Carregue o código fornecido no ESP32 usando o Arduino IDE.</li>
</ul>

<h3>Execução e Monitoramento</h3>
<ul>
    <li>Ligue o sistema e monitore a saída do serial monitor no Arduino IDE para verificar os valores de BPM.</li>
    <li>Acompanhe a publicação dos dados em tempo real na plataforma Ubidots.</li>
</ul>

<h2>Software Desenvolvido e Documentação de Código</h2>
<p>Neste diretório é possível encontrar o código do projeto com explicações do funcionamento e comentários no código.</p>

<h2>Descrição do Hardware Utilizado</h2>
<ul>
    <li><strong>Microcontrolador ESP32:</strong> Responsável por ler os dados do sensor ECG e enviar os dados para a nuvem através de WiFi.</li>
    <li><strong>Sensor ECG - AD8232:</strong> Captura os sinais elétricos do coração e os converte em sinais analógicos.</li>
    <li><strong>Protoboard 400 pinos:</strong> Utilizada para realizar as conexões sem a necessidade de solda.</li>
    <li><strong>Resistor de 220 OHMS:</strong> Conectado em série com o LED para limitar a corrente.</li>
    <li><strong>LED:</strong> Indica visualmente a atividade do sensor.</li>
    <li><strong>Jumpers Macho-Fêmea:</strong> Utilizados para conectar os componentes na protoboard.</li>
</ul>

<div align="center">
    <img src="https://github.com/Victor21Bari/SensorECG/assets/84679494/b16c2fd9-32f7-451a-bdf4-7f83db93be92"  width="700px" height="400px"/>
</div>

<h2>Documentação das Interfaces, Protocolos e Módulos de Comunicação</h2>

<h3>Interfaces</h3>
<ul>
    <li><strong>Sensor AD8232 ao ESP32:</strong> Conexão analógica do sensor ao pino A0 do ESP32.</li>
    <li><strong>ESP32 ao LED:</strong> Conexão digital do pino D18 do ESP32 ao LED através de um resistor.</li>
</ul>

<h3>Protocolos</h3>
<ul>
    <li><strong>WiFi (TCP/IP):</strong> Utilizado para conectar o ESP32 à internet.</li>
    <li><strong>MQTT:</strong> Protocolo de comunicação leve utilizado para publicar os dados de frequência cardíaca na plataforma Ubidots.</li>
</ul>

<h3>Módulos de Comunicação</h3>
<ul>
    <li><strong>WiFi:</strong> Configuração e gerenciamento da conexão com a rede WiFi.</li>
    <li><strong>PubSubClient:</strong> Biblioteca utilizada para implementar o protocolo MQTT.</li>
</ul>

<h2>Comunicação/Controle via Internet e Uso do Protocolo MQTT</h2>
<p>O projeto utiliza o protocolo MQTT para comunicar os dados do sensor ECG à plataforma Ubidots via internet (TCP/IP). O ESP32 conecta-se à rede WiFi, lê os dados do sensor ECG e publica esses dados em intervalos regulares no tópico MQTT configurado. A plataforma Ubidots, por sua vez, recebe e armazena esses dados para visualização e análise em tempo real.</p>

<h3>Fluxo de Comunicação</h3>
<ol>
    <li>O ESP32 conecta-se à rede WiFi usando as credenciais fornecidas.</li>
    <li>O sensor ECG AD8232 captura os sinais elétricos do coração.</li>
    <li>O ESP32 lê os dados analógicos do sensor e os processa para calcular a frequência cardíaca.</li>
    <li>Os dados de BPM são formatados e publicados no tópico MQTT específico.</li>
    <li>A plataforma Ubidots recebe os dados e os exibe em um painel para monitoramento.</li>
</ol>
