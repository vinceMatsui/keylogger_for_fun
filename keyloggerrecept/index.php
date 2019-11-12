<?php


if(isset($_POST['data'])){
  $filename = 'data.txt';
  $file = fopen($filename, 'a');
  // fwrite($file, $_POST['data']);
  $dataArray = explode(" ", $_POST['data']);

  foreach($dataArray as $chara){

  }
  fwrite($file, $dataclean);
  fclose();
}


?>
