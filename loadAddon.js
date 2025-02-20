import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const cppAddon = require('./cpp-addon/build/Release/cpp_addon.node');
export default cppAddon;
