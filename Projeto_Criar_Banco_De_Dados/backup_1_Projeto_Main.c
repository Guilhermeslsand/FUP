void menu_principal ()
{
  printf("\n");
  printf ("\t\t\t\t  Bancos de Dados\n");
  printf ("\t\t\t\t   Menu de Dados\n");
  printf ("\t\t\t=================================\n");
  printf ("\t\t\t|\t                        |\n");
  printf("\t\t\t| 1 - Criar Uma Ficha           |\n");
  printf("\t\t\t| 2 - Buscar Uma Fihca          |\n");
  printf("\t\t\t| 3 - Excluir Uma Ficha         |\n");
  printf("\t\t\t| 4 - Alterar Uma Ficha         |\n");
  printf("\t\t\t| 5 - Imprimir Todas as Fichas  |\n");
  printf("\t\t\t| 0 - Sair                      |\n");
  printf ("\t\t\t|\t                        |\n");
  printf ("\t\t\t=================================\n");
  printf ("\n\n");
  printf("\t\t\tPor favor, selecione uma opcao: ");
}


void lerDoArquivo ()
{
  int l = 0,j=0;
  arq = fopen(FILE_NAME, "rt");
  if(arq)
  {
    fscanf(arq, "%d\n", &n_fichas);
    for(i=0; i<n_fichas; i++)
    {
      fgets(pes.nome, tam_nome, arq);
      fscanf(arq, "%f\n", &pes.altura);
      fscanf(arq, "%d\n", &pes.idade);
      fscanf(arq, "%d\n", &pes.id);
      fgets(pes.telefone, tam_tel, arq);
      fscanf(arq, "%d\n", &pes.dia);
      fscanf(arq, "%d\n", &pes.mes);
      fscanf(arq, "%d\n", &pes.ano);
      p[i] = pes;
    }
    fclose(arq);
  }

  else
  {
    arq = fopen(FILE_NAME, "w+t");
    if(arq)
    {
      fscanf(arq, "%d\n", &n_fichas);
      for(i = 0; i < n_fichas; i++)
      {
        fgets(pes.nome, tam_nome, arq);
        fscanf(arq, "%f\n", &pes.altura);
        fscanf(arq, "%d\n", &pes.idade);
        fscanf(arq, "%d\n", &pes.id);
        fgets(pes.telefone, tam_tel, arq);
        fscanf(arq, "%d\n", &pes.dia);
        fscanf(arq, "%d\n", &pes.mes);
        fscanf(arq, "%d\n", &pes.ano);
        p[i] = pes;
      }
      fclose(arq);
    }
    else
    {
      printf("Erro na abertura do arquivo\n");
    }
  }
}

void salvarEmArquivo ()
{
  arq = fopen(FILE_NAME, "wt");
  if(arq)
  {
    fprintf(arq, "%d\n", n_fichas);
    for(i = 0; i < n_fichas; i++)
    {
      fprintf(arq, "%s", p[i].nome);
      fprintf(arq, "%1.2f\n", p[i].altura);
      fprintf(arq, "%d\n", p[i].idade);
      fprintf(arq, "%d\n", p[i].id);
      fprintf(arq, "%s", p[i].telefone);
      fprintf(arq, "%d\n", p[i].dia);
      fprintf(arq, "%d\n", p[i].mes);
      fprintf(arq, "%d\n", p[i].ano);
    }
    fclose(arq);
  }

  else
  {
    printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
  }
}

void* alocar_memoria_vetor (void* pont)
{
  pont = (size_t*) malloc(tam_vet * sizeof(size_t));
  if( pont== NULL)
  {
    printf("Erro: Espaco em memoria insuficiente\n");
    exit(1);
  }
  return pont;
}

int validar_pessoa()
{
  for(i = 0; i < n_fichas; i++)
  {
    if(strcmp(pes.nome,p[i].nome) == 0 && pes.dia == p[i].dia
    && pes.mes == p[i].mes && pes.ano == p[i].ano)
    {
      printf("\nEssa pessoa já foi cadastrada\n");
      cont = 1;
    }
  }
  return cont;
}

int validar_id()
{
  for(i = 0; i < n_fichas; i++)
  {
    if(pes.id == p[i].id)
    {
      printf("\nEsse id já foi cadastrado\n\n");
      cont = 1;
    }
  }
  return cont;
}

int validar_telefone()
{
  if(strcmp(pes.telefone ,"0\n")!=0)
  {
    for(i = 0; i < n_fichas; i++)
    {
      if(strcmp(pes.telefone ,p[i].telefone)==0)
      {
        printf("\nEsse telefone já foi cadastrado\n\n");
        cont = 1;
      }
    }
  }
  return cont;
}

void gerar_dados ()
{
  lerDoArquivo();
  if(n_fichas < tam_vet)
  {
    do
    {
      printf("\nDigite o Nome:\n");
      getchar();
      fgets(pes.nome, tam_nome, stdin);

      for(int j = 0; j < tam_nome; j++)
      {
        pes.nome[j] = toupper(pes.nome[j]);
      }

      printf("Digite a data de Nascimento: (Exemplo: 01/01/2000)\n");
      scanf("%d %d %d", &pes.dia, &pes.mes, &pes.ano);
      cont = validar_pessoa();
    }while(cont!=0);

    printf("Digite a Altura:\n");
    scanf("%f", &pes.altura);
    printf("Digite a Idade:\n");
    scanf("%d", &pes.idade);

    do
    {
      printf("Digite o ID: Ex:(1111)\n");
      printf("Tem que ter 4 digitos\n");
      printf("Nao pode colocar 0 nos 3 primeiros digitos\n");
      scanf("%d", &pes.id);
      cont = validar_id();
    }while(cont!=0);

    do
    {
      printf("Digite o Telefone: (Exemplo: +55 11 98000-0000)\n");
      getchar();
      printf("Caso não queria colocar um numero digite 0\n");
      fgets(pes.telefone, tam_tel, stdin);
      cont = validar_telefone();
    }while(cont!=0);

    p[n_fichas] = pes;
    n_fichas++;
    salvarEmArquivo();
  }

  else
  {
    printf("\nVetor cheio\n");
  }

  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

void forma_busca ()
{
  do
  {
    printf("Por favor, selecione uma opcao:  ");
    scanf("%d", &opcao);
    switch (opcao)
    {
      case 1:
        getchar();
        printf("\nQual nome você quer buscar?\n");
        fgets(pes.nome, tam_nome, stdin);
        for(i = 0; i < tam_nome; i++)
        {
          pes.nome[i] = toupper(pes.nome[i]);
        }
      break;

      case 2:
        printf("\nQual id você deseja buscar?\n");
        scanf("%d", &pes.id);
      break;

      default:
        printf("\nOpcao invalida\n");
      break;
    }
  }while(opcao < 1 || opcao > 2);
}

void nao_encontrou ()
{
  if(enc == 0)
  {
    printf("\nFicha nao encontrada\n");
  }

  else
  {
    printf("\nOperacao feita com sucesso\n");
  }
}

void buscar_ficha()
{
  lerDoArquivo();
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por id.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < n_fichas; i++)
      {
        if(strcmp(pes.nome,p[i].nome)==0)
        {
          printf("\nNome---%s", p[i].nome);
          printf("Altura---%1.2f\n", p[i].altura);
          printf("Idade---%d\n", p[i].idade);
          printf("Id---%d\n", p[i].id);
          printf("Telefone---%s", p[i].telefone);
          printf("Aniversario---%d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
          enc=1;
        }
      }
      nao_encontrou();
    break;

    case 2:
      lerDoArquivo();
      for(i = 0; i < tam_vet; i++)
      {
        if(pes.id == p[i].id)
        {
          printf("\nNome---%s", p[i].nome);
          printf("Altura---%1.2f\n", p[i].altura);
          printf("Idade---%d\n", p[i].idade);
          printf("Id---%d\n", p[i].id);
          printf("Telefone---%s", p[i].telefone);
          printf("Aniversario---%d/%d/%d", p[i].dia, p[i].mes, p[i].ano);
          enc=1;
        }
      }
      nao_encontrou();
    break;

    default:
      nao_encontrou();
    break;
  }
  salvarEmArquivo();
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

void excluir_ficha ()
{
  lerDoArquivo();
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por id.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(p[i].nome,pes.nome) == 0)
        {
          printf("\nEssa é a ficha que vai ser excluida\n");
          printf("O nome eh: %s", p[i].nome);
          printf("O id eh: %d\n", p[i].id);
          while(i > tam_vet)
          {
            p[i] = p[i+1];
            i++;
          }
          n_fichas--;
          enc=1;
        }
      }
      nao_encontrou();
    break;

    case 2:
      for(i = 0 ; i < tam_vet; i++)
      {
        if(pes.id == p[i].id)
        {
          printf("\nEssa é a ficha que vai ser excluida\n");
          printf("O nome eh: %s", p[i].nome);
          printf("O id eh: %d\n", p[i].id);
          while(i < tam_vet-1)
          {
            p[i] = p[i+1];
            i++;
          }
          n_fichas--;
          enc=1;
        }
      }
      nao_encontrou();
    break;

    default:
      nao_encontrou();
    break;
  }
  salvarEmArquivo();
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

struct pessoa alteraracao_ficha()
{
  do
  {
    printf("\nO nome atual eh: %s", p[i].nome);
    getchar();
    printf("Digite o novo nome:\n");
    fgets(pes.nome,tam_nome,stdin);
    for(int j = 0; j < tam_nome; j++)
    {
      pes.nome[j] =  toupper(pes.nome[j]);
    }
    printf("\nA data atual eh: %d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
    printf("Digite a nova data de nascimento:\n");
    scanf("%d %d %d", &pes.dia, &pes.mes, &pes.ano);
    cont = validar_pessoa();
  }while(cont!=0);

  printf("\nA altura atual eh: %1.2f\n", p[i].altura);
  printf("Digite a nova altura:\n");
  scanf("%f", &pes.altura);
  printf("\nA idade atual eh: %d\n", p[i].idade);
  printf("Digite a nova idade:\n");
  scanf("%d", &pes.idade);

  do
  {
    printf("\nO ID atual eh: %d\n", p[i].id);
    printf("Digite o novo ID:\n");
    scanf("%d", &pes.id);
    cont = validar_id();
  }while(cont!=0);

  do
  {
    printf("\nO telefone atual eh: %s", p[i].telefone);
    getchar();
    printf("Digite o novo telefone:\n");
    fgets(pes.telefone,tam_tel,stdin);
    cont = validar_telefone();
  }while(cont!=0);
  return pes;
}

void alterar_ficha()
{
  lerDoArquivo();
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por id.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(pes.nome,p[i].nome) == 0)
        {
          enc=1;
          p[i]=alteraracao_ficha();
        }
      }
      nao_encontrou();
    break;

    case 2:
      for(i = 0; i < tam_vet; i++)
      {
        if(pes.id == p[i].id)
        {
          enc=1;
          p[i] = alteraracao_ficha();
        }
      }
      nao_encontrou();
    break;

    default:
      nao_encontrou();
    break;
  }
  salvarEmArquivo();
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

void imprimir_ficha()
{
  lerDoArquivo();
  if(n_fichas == 0)
  {
    printf("\nNão existe fihcas cadastradas\n");
  }
  else
  {
    for(i = 0; i < n_fichas; i++)
    {
      printf("\nNome---%s", p[i].nome);
      printf("Altura---%1.2f\n", p[i].altura);
      printf("Idade---%d\n", p[i].idade);
      printf("Id---%d\n", p[i].id);
      printf("Telefone---%s", p[i].telefone);
      printf("Aniversario---%d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
    }
  }
  salvarEmArquivo();
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}
