<?php
$url = 'https://rss.nytimes.com/services/xml/rss/nyt/World.xml';
$xml = simplexml_load_file($url) or die("Can't connect to URL");

?>
<?php //print_r($xml); ?>
<?php
$i = 0;
foreach ($xml->channel->item as $item) {
    //printf('<li><a href="%s">%s</a></li>', $item->link, $item->title);
    //printf('%s', $item->title);
    printf($i);
    printf("=");
    $clean = str_replace( "‘", "'", $item->title);
    $clean = str_replace( "’", "'", $clean);
    $clean = str_replace( ".", "", $clean);
    $clean = str_replace( "—", "-", $clean);
    printf(strtoupper($clean));
    //printf(strtoupper($item->title));
    printf("\n");
    $i++;
}
?>  