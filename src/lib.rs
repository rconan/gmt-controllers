pub mod mount;
pub mod m1;

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
    }
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

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
