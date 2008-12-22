<?
session_start( );
/**
 @package		AnimatedCaptcha
 @author		J Watkins 		<krakjoe@krakjoe.info>
 @desc			OOP Interface to AnimCaptcha ( PHP 5 )
 @static
**/
class AnimCaptcha
{
	static $frames ;
	static $time ;
	static $num ;
	static $pause ;
	static $ops ;
	static $gifs ;
	static $rand ;
	static $math ;
	
	function AnimCaptcha( $gifs, $pause )
	{
		if( !class_exists( 'GIFEncoder' ) and !include('GIFEncoder.class.php') )
			die( 'I require GIFEncoder to be loaded before operation' );	

		self::$pause = (int)$pause ;
		self::$gifs = $gifs ;
		self::$ops = array
		(
			'minus',
			'plus',
			'times'
		);
		self::$math = array
		(
			'-',
			'+',
			'*'
		);
		
		self::$num['rand1'] = rand( 1, 9 );
		self::$num['rand2'] = rand( 1, 9 );
		self::$num['op'] = rand( 0, count( self::$math ) - 1 );
		
		self::BuildImage( );
	}
	function BuildImage( )
	{
		self::$frames[ ] = sprintf( '%s/solve.gif', self::$gifs ) ;
    	self::$time[ ]	 = 260;  
    	self::$frames[ ] = sprintf( '%s/%d.gif', self::$gifs, self::$num['rand1'] );
    	self::$time[ ]	 = self::$pause;
		self::$frames[ ] = sprintf( '%s/%s.gif', self::$gifs, self::$ops[ self::$num['op'] ] );
    	self::$time[ ]	 = self::$pause;
    	self::$frames[ ] = sprintf( '%s/%d.gif', self::$gifs, self::$num['rand2'] );
    	self::$time[ ]	 = self::$pause;
    	self::$frames[ ] = "frames/equals.gif" ;
    	self::$time [ ]  = 280;
    	foreach( self::$num as $index => $value ) $_SESSION[ $index ] = self::$num[ $value ];
	}
	function GetImage( )
	{	
		eval( sprintf( '$_SESSION["answer"] = (%d %s %d);', 
										self::$num['rand1'], 
										self::$math[ self::$num['op'] ], 
										self::$num['rand2']
		) );
		
		if( $_SESSION['answer'] < 0 ) 
			self::AnimCaptcha( self::$gifs, self::$pause );
		
		$gif = new GIFEncoder( self::$frames, self::$time, 0, 2, 0, 0, 0, "url" );
		
		if( !headers_sent( ) )
		{
			header ( 'Content-type:image/gif' );
			echo $gif->GetAnimation ( );
		}
	}
}
new AnimCaptcha( 'frames', 140 );
AnimCaptcha::GetImage( );
?>
