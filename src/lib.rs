pub mod m1;
pub mod mount;

pub trait Simulink {
    fn initialize(&mut self);
    fn step(&self);
    fn terminate(&self);
}

#[macro_export]
macro_rules! build_inputs {
    ($($name:ident, $size:expr),+) => {
        /// Controller inputs U
        #[derive(Debug)]
        pub enum U<'a> {
            $($name(&'a mut [f64; $size])),+
        }
        impl<'a> Index<usize> for U<'a> {
            type Output = f64;
            fn index(&self, index: usize) -> &Self::Output {
                match self {
                    $(U::$name(data) => &data[index]),+
                }
            }
        }
        impl<'a> IndexMut<usize> for U<'a> {
            fn index_mut(&mut self, index: usize) -> &mut Self::Output {
                match self {
                    $(U::$name(data) => &mut data[index]),+
                }
            }
        }
    };
    ($($name:ident, $size:expr,$offset:expr),+) => {
        /// Controller inputs U
        #[derive(Debug)]
        pub enum U<'a> {
            $($name(&'a mut [f64; $size])),+
        }
        impl<'a> Index<usize> for U<'a> {
            type Output = f64;
            fn index(&self, index: usize) -> &Self::Output {
                match self {
                    $(U::$name(data) => &data[index + $offset]),+
                }
            }
        }
        impl<'a> IndexMut<usize> for U<'a> {
            fn index_mut(&mut self, index: usize) -> &mut Self::Output {
                match self {
                    $(U::$name(data) => &mut data[index + $offset]),+
                }
            }
        }
    };
}
#[macro_export]
macro_rules! build_outputs {
    ($($name:ident, $size:expr),+) => {
        /// Controller outputs Y
        #[derive(Debug)]
        pub enum Y<'a> {
            $($name(&'a mut [f64; $size])),+
        }
        impl<'a> Index<usize> for Y<'a> {
            type Output = f64;
            fn index(&self, index: usize) -> &Self::Output {
                match self {
                    $(Y::$name(data) => &data[index]),+
                }
            }
        }
    };
    ($($name:ident, $size:expr,$offset:expr),+) => {
        /// Controller outputs Y
        #[derive(Debug)]
        pub enum Y<'a> {
            $($name(&'a mut [f64; $size])),+
        }
        impl<'a> Index<usize> for Y<'a> {
            type Output = f64;
            fn index(&self, index: usize) -> &Self::Output {
                match self {
                    $(Y::$name(data) => &data[index + $offset]),+
                }
            }
        }
    }
}

#[macro_export]
macro_rules! build_controller {
    ($controller:ident, U : ($($sim_u:ident -> ($enum_u:ident,$var_u:ident)),+) , Y : ($($sim_y:ident -> ($enum_y:ident,$var_y:ident)),+)) => {
        /// Controller
        pub struct Controller<'a> {
            $(pub $var_u: U<'a>,)+
            $(pub $var_y: Y<'a>,)+
        }
        paste::paste!{
        impl<'a> Controller<'a> {
            /// Creates a new controller
            pub fn new() -> Self {
                let mut this = unsafe {
                    Self {
                        $($var_u: U::$enum_u(&mut [<$controller _U>].$sim_u),)+
                        $($var_y: Y::$enum_y(&mut [<$controller _Y>].$sim_y),)+
                    }
                };
                this.initialize();
                this
            }
        }}
        paste::paste! {
        impl<'a> Simulink for Controller<'a> {
            fn initialize(&mut self) {
                unsafe {
                    [<$controller _initialize>]();
                }
            }
            fn step(&self) {
                unsafe {
                    [<$controller _step>]();
                }
            }
            fn terminate(&self) {
                unsafe {
                    [<$controller _terminate>]();
                }
            }
        }
        }
        impl<'a> Drop for Controller<'a> {
            fn drop(&mut self) {
                self.terminate()
            }
        }
        impl<'a> Iterator for &Controller<'a> {
            type Item = ();
            fn next(&mut self) -> Option<Self::Item> {
                self.step();
                Some(())
            }
        }
    };
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
