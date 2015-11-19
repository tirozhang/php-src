<?php
$fp_in = file_open("test.txt", "r") or die("Unable to open input file/n");
$fp_out = file_open("test.txt.new", "w") or die("Unable to open output file/n");
var_dump($fp_in);
while (!file_eof($fp_in)) {
    $str = file_read($fp_in, 10);
    print($str);
    file_write($fp_out, $str);
}
file_close($fp_in);
file_close($fp_out);
// echo phpinfo();


// vim600:ts=4 st=4 foldmethod=marker foldmarker=<<<,>>>
// vim600:syn=php commentstring=//%s
