using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
//using System.Threading.Tasks;

namespace unitycork
{
    public class PluginImport 
    {


        //Lets make our calls from the Plugin
        [DllImport ( "dllcork2", EntryPoint = "addition" )]
        public static extern float addition ( float val_1, float val_2 );
        [DllImport ( "dllcork2" )]
        private static extern float substraction ( float val_1, float val_2 );
        [DllImport ( "dllcork2" )]
        private static extern float multiplication ( float val_1, float val_2 );
        [DllImport ( "dllcork2" )]
        private static extern float division ( float val_1, float val_2 );

        //Lets make our calls from the Plugin
        [DllImport ( "dllcork2", EntryPoint = "testcork" )]
        public static extern float testcork (  );


        public static void Start ()
        {

            Debug.Print ( testcork ( ).ToString () );
            var i = addition ( 5, 5 );
            Debug.Print ( addition ( 5, 5 ).ToString() );
            Debug.Print ( substraction ( 10, 5 ).ToString () );
            Debug.Print ( multiplication ( 2, 5 ).ToString () );
            Debug.Print ( division ( 10, 2 ).ToString () );
        }
    }
}


