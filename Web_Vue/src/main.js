import Vue from 'vue'
import App from './App.vue'
import Bootstrap from 'bootstrap/dist/css/bootstrap.min.css'
import firebase from 'firebase'

Vue.config.productionTip = false

const firebaseConfig = {
  apiKey: "AIzaSyAXwj0o_6yJpxQ8PN_m8WFibG1pI6nPY2Q",
  authDomain: "theeraphat-a723c.firebaseapp.com",
  databaseURL: "https://theeraphat-a723c.firebaseio.com",
  projectId: "theeraphat-a723c",
  storageBucket: "theeraphat-a723c.appspot.com",
  messagingSenderId: "760802910381",
  appId: "1:760802910381:web:b589c2f99fc5cb0a"
};
firebase.initializeApp(firebaseConfig)

new Vue({
  render: h => h(App),
  Bootstrap,
}).$mount('#app')
