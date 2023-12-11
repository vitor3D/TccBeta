# Controle de Acesso com RFID e ESP32

Este é um projeto de controle de acesso utilizando um leitor RFID (RFID-RC522) e um microcontrolador ESP32. O sistema permite a liberação de acesso com base no ID de um cartão RFID válido.

## Pré-requisitos

- Placa ESP32
- Leitor RFID RFID-RC522
- Display LCD I2C (16x2)
- Bibliotecas necessárias:
  - MFRC522 (RFID)
  - LiquidCrystal_I2C (LCD)
  - WiFi
  - NTPClient
  - WiFiUdp

## Configuração

1. Conecte o leitor RFID (RFID-RC522) ao ESP32:
   - SDA: Pino 14 (ou outro pino SDA disponível no ESP32)
   - SCK: Pino 18 (ou outro pino SCK disponível no ESP32)
   - MOSI: Pino 23 (ou outro pino MOSI disponível no ESP32)
   - MISO: Pino 19 (ou outro pino MISO disponível no ESP32)
   - RST: Pino 27 (ou outro pino RST disponível no ESP32)

2. Conecte o display LCD I2C ao ESP32:
   - SDA: Pino 21 (ou outro pino SDA disponível no ESP32)
   - SCL: Pino 22 (ou outro pino SCL disponível no ESP32)

3. Defina as credenciais da sua rede Wi-Fi no código:
   ```cpp
   const char* ssid = "seu_SSID";
   const char* password = "sua_senha";
****

## Banco de dados

Primeiro, é importante compreender o conceito de pymongo e como ele interage com o MongoDB. Pymongo é um pacote python que é usado para interagir com o MongoDB. MongoDB é um banco de dados orientado a documentos que é conhecido por sua flexibilidade, desempenho e escalabilidade.
Neste código, o autor está criando um aplicativo de linha de comando para gerenciar um sistema de presença de alunos e um sistema de lista de tarefas.

Aqui estão algumas funções importantes:

insert_todo: Esta função recebe parâmetros como título, descrição, data de vencimento, prioridade e concluídos. Em seguida, cria um dicionário e insere-o na coleção 'todo' do banco de dados 'todo'.

view_all_todos: Esta função busca todos os documentos da coleção 'todo' e os exibe em um formato tabular usando o módulo tabulate.

delete_todo: Esta função recebe um título como argumento. Ele encontra um documento na coleção 'todo' onde o título corresponde ao título fornecido e o exclui.

update_todo: Esta função recebe um título e um status de concluído como argumentos. Ele encontra um documento na coleção 'todo' onde o título corresponde ao título fornecido e atualiza o status de conclusão desse documento.

add_student: Esta função é semelhante a insert_todo. Ela recebe parâmetros como nome, enter_time, leave_time, total_faltas, total_presencas e procentagem. Em seguida, cria um dicionário e insere-o na coleção 'student' do banco de dados 'todo'.

view_all_students: Esta função é semelhante a view_all_todos. Ela busca todos os documentos da coleção 'student' e os exibe em um formato tabular.

delete_student: Esta função recebe um nome como argumento. Ele encontra um documento na coleção 'student' onde o nome corresponde ao nome fornecido e o exclui.

main: Esta função serve como o driver principal para o aplicativo de linha de comando. Ele fornece ao usuário opções para executar diferentes ações, como adicionar um aluno, exibir todos os alunos, excluir um aluno, adicionar um todo, exibir todos os todos, excluir um todo, atualizar um todo e sair do aplicativo.

Referência: https://realpython.com/mongodb-and-python/
