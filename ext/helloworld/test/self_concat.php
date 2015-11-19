<?php
function self_concat($string, $n)
{
    $result = "";
    for ($i = 0; $i < $n; $i++) {
        $result .= $string;
    }
    return $result;
}

echo self_concat("One", 3);


    // vim600:ts=4 st=4 foldmethod=marker foldmarker=<<<,>>>
    // vim600:syn=php commentstring=//%s
