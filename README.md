
<h1>Projeto de Monitoramento de Sinais Cardíacos com ECG AD8232 e ESP32</h1>

<h2>Descrição do Funcionamento e Uso</h2>
<p>Este projeto mede sinais cardíacos usando um sensor ECG AD8232 e publica esses dados em tempo real na plataforma Ubidots usando o protocolo MQTT. O sistema é composto por um microcontrolador ESP32, que lê os dados do sensor ECG, processa esses dados para calcular a frequência cardíaca em BPM (batimentos por minuto) e publica os resultados na plataforma Ubidots através de uma conexão WiFi.</p>

<h2>Passos para Reproduzir o Projeto</h2>

<h2>IDE Arduino</h2>
<p>Visite o <a href="https://www.arduino.cc" target="_blank">site oficial do Arduino</a> e vá até a seção de downloads. Escolha a versão da IDE do Arduino que seja compatível com seu sistema operacional.</p>
<p>Execute o instalador que você baixou e siga as instruções exibidas na tela. Durante a instalação, certifique-se de que todos os drivers necessários sejam instalados.</p>

<h3>Adicionar o URL do Gerenciador de Placas para a ESP32:</h3>
<p>Na IDE do Arduino, vá até "Arquivo" > "Preferências". No campo "URLs Adicionais de Gerenciadores de Placas", insira as URL´s abaixo:</p>
<p><a href="https://arduino.esp8266.com/stable/package_esp8266com_index.json" target="_blank">https://arduino.esp8266.com/stable/package_esp8266com_index.json</a></p>
<p><a href="https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json" target="_blank">https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json</a></p>

<h3>Selecionar a Placa ESP32:</h3>
<p>Depois de instalar, vá para "Ferramentas" > "Placa:" e selecione o modelo específico da sua ESP32 na lista de opções disponíveis.</p>

<h3>Conectar a ESP32 ao Computador:</h3>
<p>Conecte a Esp32 em um cabo USB e plugue em um entrada USB do Computador.</p>

<h3>Selecionar a porta conectada do USB</h3>
<p>Acesse "Ferramentas" > "Porta" e selecione a porta COM que corresponde à sua ESP32.</p>

<p>Clique em "OK".</p>
<p>Pronto, sua placa estará configurada com o Computador.</p>

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

<h3>Para configurar com a plataforma Ubidots, siga esses passos:</h3>

<p>Acesse o site: <a href="https://ubidots.com/">Ubidots</a></p>
<p>Crie uma conta.</p>

<div align="center">
    <img src="https://github.com/Victor21Bari/SensorECG/assets/84679494/21d58d1b-b1af-4871-b56e-8b6165ad852d"  width="700px" height="400px"/>
</div>
<p>Após o login, clique em "Devices" > "Device" e clique no botão verde de "+" para adicionar um dispositivo. Nomeie como prefirir.  </p>

<div align="center">
    <img src="https://github.com/Victor21Bari/SensorECG/assets/84679494/aac3bcbc-fc8d-4344-a022-be445cc34c48"  width="700px" height="400px"/>
</div>

<p>Após adicionar o "Devices" clique nele e dentro do dispositivo você verá uma tela para adicionar uma variavel, adicione com o nome que desejar.</p>
<p>Assim que criar a variável,você terá acesso ao gráfico com os valores recebidos do sensor AD8232 pelo protocolo MQTT. </p>

<div align="center">
    <img src="https://github.com/Victor21Bari/SensorECG/assets/84679494/46bdaea8-66c7-4c48-998e-e2cfef682489"  width="700px" height="400px"/>
</div>

<h2>Software Desenvolvido e Documentação de Código</h2>
<p>Neste diretório é possível encontrar o código do projeto com explicações do funcionamento e comentários no código.</p>
<p>O software utilizado foi o circuito.io para a criação do modelo 3d do prototipo.</p>
<div align="center">
    <img src="https://github.com/Victor21Bari/SensorECG/assets/84679494/c9be3b64-e2e2-40d3-ab69-0e049163ced6"  width="700px" height="400px"/>
</div>

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
